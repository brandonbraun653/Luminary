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
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/hardware/status_led.hpp>
#include <Luminary/model/mdl_common.hpp>

namespace Luminary::Hardware::StatusLED
{
  /*-------------------------------------------------------------------------------
  Private Function Declaration
  -------------------------------------------------------------------------------*/
  static void heartbeat_proc();
  static void failed_config_proc();
  static void network_disconnected_proc();
  static void network_connecting_proc();
  static void network_connected_proc();

  /*-------------------------------------------------------------------------------
  Private Types
  -------------------------------------------------------------------------------*/
  using LedProcessor = void ( * )( void );

  /*-------------------------------------------------------------------------------
  Private Data
  -------------------------------------------------------------------------------*/
  static size_t s_init_status;
  static Chimera::GPIO::GPIO_sPtr s_status_led;
  static Chimera::Threading::Mutex s_status_mutex;
  static BlinkPattern s_current_pattern;

  static const std::array<LedProcessor, static_cast<size_t>(BlinkPattern::NUM_OPTIONS)> sLedProcs = {
    heartbeat_proc,
    failed_config_proc,
    network_disconnected_proc,
    network_connecting_proc,
    network_connected_proc
  };


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
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
      s_current_pattern = BlinkPattern::HEARTBEAT;

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


  void runStatusProcessing()
  {
    if ( s_init_status != Chimera::DRIVER_INITIALIZED_KEY )
    {
      return;
    }

    /*-------------------------------------------------
    Safely grab the latest pattern info and invoke it
    -------------------------------------------------*/
    s_status_mutex.lock();
    BlinkPattern patternCopy = s_current_pattern;
    s_status_mutex.unlock();

    sLedProcs[static_cast<size_t>(patternCopy)]();
  }


  void updateStatus( const BlinkPattern pattern )
  {
    s_status_mutex.lock();
    s_current_pattern = pattern;
    s_status_mutex.unlock();
  };


  /*-------------------------------------------------------------------------------
  Private Functions
  -------------------------------------------------------------------------------*/
  static void heartbeat_proc()
  {
    static size_t s_last_status_led_processing = 0;

    /*-------------------------------------------------
    Initialize local variables
    -------------------------------------------------*/
    size_t currentTick = Chimera::millis();
    size_t ledPeriod = 0;

    /*-------------------------------------------------
    Grab the latest led period info and decide to update
    -------------------------------------------------*/
    Model::getDataSafe( Model::CommonData::DBG_LED_STATUS_BLINK_PERIOD, &ledPeriod, sizeof( ledPeriod ), 100 );

    if ( ( currentTick - s_last_status_led_processing ) >= ledPeriod )
    {
      s_last_status_led_processing = currentTick;
      StatusLED::toggleState();
    }
  }

  static void failed_config_proc()
  {
    // no transition
  }

  static void network_disconnected_proc()
  {
    // no transition
  }

  static void network_connecting_proc()
  {
    // no transition
  }

  static void network_connected_proc()
  {
    // Display the blinky then transition to heartbeat
  }

}  // namespace Luminary::Hardware
