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
  /*-------------------------------------------------------------------------------
  Private Data
  -------------------------------------------------------------------------------*/
  static constexpr size_t NUM_CFG_GPIO = 6;
  static constexpr size_t UPPER_BITS_BUG_MASK = 0x30;

  static RF24::LogicalAddress sBootAddress;
  static uint8_t sBootBitField;
  static bool sAddressStale;

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

  static const std::array<RF24::LogicalAddress, 64> sNodeAddress = {
    00000,  // 0: Master node
    00001,
    00002,
    00003,
    00004,
    00005,  // 5
    00011,
    00021,
    00031,
    00041,
    00051,  // 10
    00012,
    00022,
    00032,
    00042,
    00052,  // 15
    00013,
    00023,
    00033,
    00043,
    00053,  // 20
    00014,
    00024,
    00034,
    00044,
    00054,  // 25
    00015,
    00025,
    00035,
    00045,
    00055,  // 30
    00111,
    00211,
    00311,
    00411,
    00511,  // 35
    00112,
    00212,
    00312,
    00412,
    00512,  // 40
    00113,
    00213,
    00313,
    00413,
    00513,  // 45
    00114,
    00214,
    00314,
    00414,
    00514,  // 50
    00115,
    00215,
    00315,
    00415,
    00515,  // 55
    00121,
    00221,
    00321,
    00421,
    00521,  // 60
    00122,
    00222,
    00322
  };


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
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
      /*------------------------------------------------
      Due to yet another hardware bug (rev 2), address
      bits PA1 and PA2 need are forced to read zero.
      ------------------------------------------------*/
//      if ( ( idx == 0 ) || ( idx == 1 ) )
//      {
//        continue;
//      }

      /*-------------------------------------------------
      Initialize the gpio configuration structure
      -------------------------------------------------*/
      cfg.clear();
      cfg.alternate = Alternate::NONE;
      cfg.drive     = Drive::INPUT;
      cfg.pin       = sCfgPins[ idx ];
      cfg.port      = sCfgPorts[ idx ];
      cfg.pull      = Pull::PULL_DN;
      cfg.threaded  = false;
      cfg.validity  = true;

      /*-------------------------------------------------
      Initialize the GPIO hardware and read out it's state
      -------------------------------------------------*/
      result |= pin->init( cfg, TIMEOUT_DONT_WAIT );
      result |= pin->getState( pinState, TIMEOUT_DONT_WAIT );

      /*-------------------------------------------------
      Set the appropriate bit field for the current pin.
      Reverse the direction so the MSB is on the right
      according to how the hardware pin is set up.
      -------------------------------------------------*/
      if( pinState == State::LOW )
      {
        sBootBitField |= 1u << ( NUM_CFG_GPIO - idx - 1 );
      }
      else
      {
        sBootBitField &= ~( 1u << ( NUM_CFG_GPIO - idx - 1 ) );
      }
    }


    /*------------------------------------------------
    Let the next invoker of getNodeAddress() know it
    should re-parse the bit field.
    ------------------------------------------------*/
    sAddressStale = true;

    return result;
  }


  RF24::LogicalAddress getNodeAddress()
  {
    using namespace Aurora::Math;

    /*-------------------------------------------------
    Convert the bitfield into a useful address
    -------------------------------------------------*/
    if ( sAddressStale && ( sBootBitField < sNodeAddress.size() ) )
    {
      /*-------------------------------------------------
      Rev 2.0 of the PWM driver hardware has a bug where
      the upper two bits are completely invalid. Given the
      number of nodes used in the wedding do not reach to
      the range in those upper two bits, simply assume only
      the lower four are valid.
      -------------------------------------------------*/
      if ( ( sBootBitField & UPPER_BITS_BUG_MASK ) == UPPER_BITS_BUG_MASK )
      {
        sBootBitField &= ~( UPPER_BITS_BUG_MASK );
      }

      /*-------------------------------------------------
      Use the remaining bits to look up
      -------------------------------------------------*/
      sBootAddress  = sNodeAddress[ sBootBitField ];
      sAddressStale = false;
    }
    // else do nothing, the address has been parsed

    return sBootAddress;
  }

}  // namespace Luminary::Hardware::Boot
