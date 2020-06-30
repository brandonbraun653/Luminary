/********************************************************************************
 *  File Name:
 *    boot_config.cpp
 *
 *  Description:
 *    Implementation of the boot configuration interface
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>

/* Aurora Includes */
#include <Aurora/math>

/* Chimera Includes */
#include <Chimera/gpio>
#include <Chimera/thread>

/* RF24 Includes */
#include <RF24Node/common>
#include <RF24Node/src/network/definitions.hpp>

/* Luminary Includes */
#include <Luminary/hardware/boot_config.hpp>

namespace Luminary::Hardware::Boot
{
  static constexpr size_t NUM_CFG_GPIO = 6;

  static const std::array<Chimera::GPIO::Pin, NUM_CFG_GPIO> sCfgPins{
    1,  // PA1
    2,  // PA2
    0,  // PB0
    15, // PA15
    8,  // PA8
    1,  // PB1
  };

  static const std::array<Chimera::GPIO::Port, NUM_CFG_GPIO> sCfgPorts{
    Chimera::GPIO::Port::PORTA,
    Chimera::GPIO::Port::PORTA,
    Chimera::GPIO::Port::PORTB,
    Chimera::GPIO::Port::PORTA,
    Chimera::GPIO::Port::PORTA,
    Chimera::GPIO::Port::PORTB
  };

  static RF24::LogicalAddress sBootAddress;
  static uint8_t sBootBitField;

  Chimera::Status_t readConfiguration()
  {
    using namespace Chimera::GPIO;
    using namespace Chimera::Threading;

    PinInit cfg;
    GPIO_sPtr pin;
    State pinState;

    /*-------------------------------------------------
    Initialize variables
    -------------------------------------------------*/
    pin           = Chimera::GPIO::create_shared_ptr();
    pinState      = State::LOW;
    sBootBitField = 0;

    if( !pin )
    {
      return Chimera::CommonStatusCodes::FAIL;
    }

    /*-------------------------------------------------
    Read through each configuration pin and grab its state
    -------------------------------------------------*/
    auto result = Chimera::CommonStatusCodes::OK;
    for ( size_t idx = 0; idx < NUM_CFG_GPIO; idx++ )
    {
      /*-------------------------------------------------
      Mitigates a hardware bug that currently has bit 2 always
      set. Until this is fixed, forcefully set to 0.
      -------------------------------------------------*/
      if ( idx == 2 )
      {
        #pragma message("Bit 2 of boot config forcefully set to 0")
        sBootBitField &= ~( 1u << idx );
        continue;
      }

      /*-------------------------------------------------
      Initialize the gpio configuration structure
      -------------------------------------------------*/
      cfg.clear();
      cfg.alternate = Alternate::NONE;
      cfg.drive     = Drive::INPUT;
      cfg.pin       = sCfgPins[ idx ];
      cfg.port      = sCfgPorts[ idx ];
      cfg.pull      = Pull::PULL_UP;
      cfg.threaded  = false;
      cfg.validity  = true;

      /*-------------------------------------------------
      Initialize the GPIO hardware and read out it's state
      -------------------------------------------------*/
      result |= pin->init( cfg, TIMEOUT_DONT_WAIT );
      result |= pin->getState( pinState, TIMEOUT_DONT_WAIT );

      /*-------------------------------------------------
      Set the appropriate bit field for the current pin
      -------------------------------------------------*/
      if( pinState == State::HIGH )
      {
        sBootBitField |= 1u << idx;
      }
      else
      {
        sBootBitField &= ~( 1u << idx );
      }
    }

    return result;
  }

  RF24::LogicalAddress getNodeAddress()
  {
    using namespace Aurora::Math;

    /*-------------------------------------------------
    Convert the bitfield into a useful address
    -------------------------------------------------*/
    static_assert( sizeof( sBootBitField ) == 1, "Bit field should only occupy one byte" );

    // Special case for development. STM32L432KC nucleo boards will have this value.
    if ( ( sBootBitField == 0x37 ) || ( sBootBitField == 0x3F ) )
    {
      return RF24::RootNode0;
    }

    size_t octalAddress = asBase( sBootBitField, BaseType::DECIMAL, BaseType::OCTAL );
    sBootAddress = static_cast<RF24::LogicalAddress>( octalAddress );

    return sBootAddress;
  }

}  // namespace Luminary::Hardware::Boot
