/********************************************************************************
 *  File Name:
 *    status_led.cpp
 *
 *  Description:
 *    Status LED driver
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/constants/common.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/gpio>

/* Luminary Includes */
#include <Luminary/hardware/status_led.hpp>
#include <Luminary/model/mdl_common.hpp>

namespace Luminary::Hardware::StatusLED
{
  static size_t s_init_status;

  static Chimera::GPIO::GPIO_sPtr s_status_led;

  static size_t s_last_status_led_processing;
  static size_t s_status_led_period;


  Chimera::Status_t initialize()
  {
    using namespace Chimera::GPIO;

    auto result = Chimera::CommonStatusCodes::OK;

    /*-------------------------------------------------
    Only bother initializing if it hasn't been performed yet
    -------------------------------------------------*/
    if( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      s_init_status = ~Chimera::DRIVER_INITIALIZED_KEY;

      /*-------------------------------------------------
      Set up the pin configuration data
      -------------------------------------------------*/
      Chimera::GPIO::PinInit pinInit;
      pinInit.clear();
      pinInit.alternate = Alternate::NONE;
      pinInit.drive     = Drive::OUTPUT_PUSH_PULL;
      pinInit.pin       = 14;
      pinInit.port      = Port::PORTC;
      pinInit.pull      = Pull::NO_PULL;
      pinInit.state     = State::LOW;
      pinInit.threaded  = true;
      pinInit.validity  = true;

      /*-------------------------------------------------
      Initialize the GPIO pin
      -------------------------------------------------*/
      s_status_led = Chimera::GPIO::create_shared_ptr();
      result |= s_status_led->init( pinInit, 100 );

      if( result == Chimera::CommonStatusCodes::OK )
      {
        s_init_status = Chimera::DRIVER_INITIALIZED_KEY;
      }

      /*-------------------------------------------------
      Grab the latest update rate associated with the status led heartbeat
      -------------------------------------------------*/
      s_last_status_led_processing = Chimera::millis();
      result |= Model::getDataSafe( Model::CommonData::DBG_LED_STATUS_BLINK_PERIOD, &s_status_led_period,
                                    sizeof( s_status_led_period ), 100 );
    }

    return result;
  }

  void setState( const bool state )
  {
    if( s_init_status == Chimera::DRIVER_INITIALIZED_KEY )
    {
      auto outputState = state ? Chimera::GPIO::State::HIGH : Chimera::GPIO::State::LOW;
      s_status_led->setState( outputState, 100 );
    }
  }

  void toggleState()
  {
    if( s_init_status == Chimera::DRIVER_INITIALIZED_KEY )
    {
      s_status_led->toggle( 100 );
    }
  }

  void executeBootFlashSequence()
  {
    if( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      return;
    }

    for ( uint8_t i = 0; i < 4; i++ )
    {
      s_status_led->setState( Chimera::GPIO::State::HIGH, 100 );
      Chimera::delayMilliseconds( 65 );
      s_status_led->setState( Chimera::GPIO::State::LOW, 100 );
      Chimera::delayMilliseconds( 25 );
    }

    Chimera::delayMilliseconds( 350 );
  }

  void runHeartBeat()
  {
    if ( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      return;
    }

    auto currentTick = Chimera::millis();

    if ( ( currentTick - s_last_status_led_processing ) >= s_status_led_period )
    {
      s_last_status_led_processing = currentTick;
      StatusLED::toggleState();
    }
  }

}  // namespace Luminary::Hardware
