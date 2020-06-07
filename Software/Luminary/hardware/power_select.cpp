/********************************************************************************
 *  File Name:
 *    power_select.cpp
 *
 *  Description:
 *    Power selection driver to turn on/off various external hardware
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>
#include <cstddef>

/* Aurora Includes */
#include <Aurora/constants/common.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/gpio>
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/hardware/power_select.hpp>

namespace Luminary::Hardware::Power
{
  struct ControlBlock
  {
    Chimera::GPIO::GPIO_sPtr pin;
    //Chimera::Threading::RecursiveTimedMutex lock;
  };

  std::array<ControlBlock, Channel::NUM_OPTIONS> s_power_channels;

  static size_t s_init_status;


  void initialize()
  {
    using namespace Chimera::GPIO;

    if( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      PinInit pinInit;

      /*-------------------------------------------------
      Initialize GPIO for the external flash power control signal
      -------------------------------------------------*/
      pinInit.clear();
      pinInit.alternate = Alternate::NONE;
      pinInit.drive     = Drive::OUTPUT_PUSH_PULL;
      pinInit.pin       = 0;
      pinInit.port      = Port::PORTA;
      pinInit.pull      = Pull::NO_PULL;
      pinInit.state     = State::LOW;
      pinInit.threaded  = true;
      pinInit.validity  = true;

      s_power_channels[ EXTERNAL_FLASH ].pin = Chimera::GPIO::create_shared_ptr();
      s_power_channels[ EXTERNAL_FLASH ].pin->init( pinInit, Chimera::Threading::TIMEOUT_DONT_WAIT );

      /*-------------------------------------------------
      Initialize GPIO for the RF24 Radio power control signal
      -------------------------------------------------*/
      pinInit.clear();
      pinInit.alternate = Alternate::NONE;
      pinInit.drive     = Drive::OUTPUT_PUSH_PULL;
      pinInit.pin       = 0;
      pinInit.port      = Port::PORTA;
      pinInit.pull      = Pull::NO_PULL;
      pinInit.state     = State::LOW;
      pinInit.threaded  = true;
      pinInit.validity  = true;

      s_power_channels[ RF24_RADIO ].pin = Chimera::GPIO::create_shared_ptr();
      s_power_channels[ RF24_RADIO ].pin->init( pinInit, Chimera::Threading::TIMEOUT_DONT_WAIT );

#pragma message("Power driver not fully functioning yet")
      //s_init_status = Chimera::DRIVER_INITIALIZED_KEY;
    }
  }

  Chimera::Status_t setPowerState( const Channel channel, const bool state )
  {
    /*-------------------------------------------------
    Input protection/validation
    -------------------------------------------------*/
    if( channel >= Channel::NUM_OPTIONS )
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }
    else if( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      return Chimera::CommonStatusCodes::NOT_INITIALIZED;
    }

    /*-------------------------------------------------
    Set the requested state
    -------------------------------------------------*/
    auto gpioState = state ? Chimera::GPIO::State::HIGH : Chimera::GPIO::State::LOW;
    return s_power_channels[ channel ].pin->setState( gpioState, Chimera::Threading::TIMEOUT_100MS );
  }

}  // namespace Luminary::Hardware::Power
