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
  static size_t s_init_status;

  static Chimera::GPIO::GPIO_sPtr sPowerPin;

  static const std::array<Chimera::GPIO::Pin, Channel::NUM_OPTIONS> sCfgPins{
    3,     // PB3,     RF24_RADIO
    16,    // INVALID, EXTERNAL_FLASH
  };

  static const std::array<Chimera::GPIO::Port, Channel::NUM_OPTIONS> sCfgPorts{
    Chimera::GPIO::Port::PORTA,           // RF24_RADIO
    Chimera::GPIO::Port::UNKNOWN_PORT,    // EXTERNAL_FLASH
  };


  void initialize()
  {
    if ( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      sPowerPin = Chimera::GPIO::create_shared_ptr();


      s_init_status = Chimera::DRIVER_INITIALIZED_KEY;
    }
  }


  Chimera::Status_t setPowerState( const Channel channel, const bool state )
  {
    using namespace Chimera::GPIO;
    using namespace Chimera::Threading;

    /*-------------------------------------------------
    Input protection/validation
    -------------------------------------------------*/
    if ( channel >= Channel::NUM_OPTIONS )
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }
    else if ( !sPowerPin )
    {
      return Chimera::CommonStatusCodes::NOT_INITIALIZED;
    }

    /*-------------------------------------------------
    Protect against multithreaded access
    -------------------------------------------------*/
    auto lg = LockGuard( *sPowerPin );

    /*------------------------------------------------
    Initialize the GPIO hardware. These pins are shared with
    multiple functionalities, so it's best to reconfigure them
    each time they are accessed.
    ------------------------------------------------*/
    PinInit pinInit;

    pinInit.clear();
    pinInit.alternate = Alternate::NONE;
    pinInit.drive     = Drive::OUTPUT_PUSH_PULL;
    pinInit.pin       = sCfgPins[ channel ];
    pinInit.port      = sCfgPorts[ channel ];
    pinInit.pull      = Pull::NO_PULL;
    pinInit.state     = State::LOW;
    pinInit.threaded  = true;
    pinInit.validity  = true;

    if ( sPowerPin->init( pinInit, TIMEOUT_DONT_WAIT ) != Chimera::CommonStatusCodes::OK )
    {
      return Chimera::CommonStatusCodes::FAIL;
    }

    /*-------------------------------------------------
    Set the requested state
    -------------------------------------------------*/
    auto gpioState = state ? State::HIGH : State::LOW;
    return sPowerPin->setState( gpioState, TIMEOUT_DONT_WAIT );
  }

}    // namespace Luminary::Hardware::Power
