/********************************************************************************
 *  File Name:
 *    pwm_output.cpp
 *
 *  Description:
 *    PWM driver implementation for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/gpio>
#include <Chimera/pwm>

/* Luminary Includes */
#include <Luminary/hardware/pwm_output.hpp>


namespace Luminary::Hardware::PWM
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static std::array<Chimera::PWM::PWM_sPtr, NUM_OPTIONS> pwmChannels;
  static std::array<float, NUM_OPTIONS> pwmScalingConstants;

  /*-------------------------------------------------------------------------------
  Functions
  -------------------------------------------------------------------------------*/
  void initialize()
  {
    using namespace Chimera::PWM;

    /*-------------------------------------------------
    Initialize the static module data
    -------------------------------------------------*/
    pwmChannels[ PWM_CH_0 ] = Chimera::PWM::create_shared_ptr();
    pwmChannels[ PWM_CH_1 ] = Chimera::PWM::create_shared_ptr();
    pwmChannels[ PWM_CH_2 ] = Chimera::PWM::create_shared_ptr();

    pwmScalingConstants[ PWM_CH_0 ] = 0.5f;
    pwmScalingConstants[ PWM_CH_1 ] = 0.5f;
    pwmScalingConstants[ PWM_CH_2 ] = 0.5f;

    /*-------------------------------------------------
    Configure some common PWM driver attributes
    -------------------------------------------------*/
    DriverConfig cfg;
    cfg.validity = true;

    cfg.timer.countDirection = Chimera::Timer::Direction::COUNT_UP;
    cfg.timer.overwrite      = true;
    cfg.timer.peripheral     = Chimera::Timer::Peripheral::TIMER2;
    cfg.timer.reloadValue    = 1000;
    cfg.timer.prescaler      = 80;
    cfg.timer.validity       = true;

    /*------------------------------------------------
    Configure output channel 0
    ------------------------------------------------*/
    cfg.pwm.outputChannel = Chimera::Timer::Channel::CHANNEL_1;
    cfg.pwm.compareMatch  = 100;
    cfg.pwm.polarity      = Chimera::Timer::PWM::Polarity::ACTIVE_LOW;
    cfg.pwm.mode          = Chimera::Timer::PWM::Mode::EDGE_ALIGNED;
    cfg.pwm.validity      = true;

    cfg.outputPin.pin       = 0;
    cfg.outputPin.port      = Chimera::GPIO::Port::PORTA;
    cfg.outputPin.alternate = Chimera::GPIO::Alternate::TIM2_CH1;
    cfg.outputPin.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    cfg.outputPin.threaded  = false;
    cfg.outputPin.validity  = true;

    pwmChannels[ PWM_CH_0 ]->init( cfg );
    pwmChannels[ PWM_CH_0 ]->toggleOutput( false );
    pwmChannels[ PWM_CH_0 ]->setDutyCyle( PWM_MIN_DUTY_CYCLE );

    /*------------------------------------------------
    Configure output channel 1
    ------------------------------------------------*/
    cfg.pwm.outputChannel = Chimera::Timer::Channel::CHANNEL_2;
    cfg.pwm.compareMatch  = 100;
    cfg.pwm.polarity      = Chimera::Timer::PWM::Polarity::ACTIVE_LOW;
    cfg.pwm.mode          = Chimera::Timer::PWM::Mode::EDGE_ALIGNED;
    cfg.pwm.validity      = true;

    cfg.outputPin.pin       = 1;
    cfg.outputPin.port      = Chimera::GPIO::Port::PORTA;
    cfg.outputPin.alternate = Chimera::GPIO::Alternate::TIM2_CH2;
    cfg.outputPin.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    cfg.outputPin.threaded  = false;
    cfg.outputPin.validity  = true;

    pwmChannels[ PWM_CH_1 ]->init( cfg );
    pwmChannels[ PWM_CH_1 ]->toggleOutput( false );
    pwmChannels[ PWM_CH_1 ]->setDutyCyle( PWM_MIN_DUTY_CYCLE );

    /*------------------------------------------------
    Configure output channel 2
    ------------------------------------------------*/
    cfg.pwm.outputChannel = Chimera::Timer::Channel::CHANNEL_3;
    cfg.pwm.compareMatch  = 100;
    cfg.pwm.polarity      = Chimera::Timer::PWM::Polarity::ACTIVE_LOW;
    cfg.pwm.mode          = Chimera::Timer::PWM::Mode::EDGE_ALIGNED;
    cfg.pwm.validity      = true;

    cfg.outputPin.pin       = 2;
    cfg.outputPin.port      = Chimera::GPIO::Port::PORTA;
    cfg.outputPin.alternate = Chimera::GPIO::Alternate::TIM2_CH3;
    cfg.outputPin.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    cfg.outputPin.threaded  = false;
    cfg.outputPin.validity  = true;

    pwmChannels[ PWM_CH_2 ]->init( cfg );
    pwmChannels[ PWM_CH_2 ]->toggleOutput( false );
    pwmChannels[ PWM_CH_2 ]->setDutyCyle( PWM_MIN_DUTY_CYCLE );
  }

  void setOutputState( const Channel channel, const bool state )
  {
    if( channel < NUM_OPTIONS )
    {
      pwmChannels[ channel ]->toggleOutput( state );
    }
  }

  void updateDutyCycle( const Channel channel, const DutyCycle_t dc )
  {
    if( channel < NUM_OPTIONS )
    {
      float val = static_cast<float>( dc ) * pwmScalingConstants[ channel ];
      pwmChannels[ channel ]->setDutyCyle( static_cast<size_t>( val ) );
    }
  }


  void setScale( const Channel channel, const float scale )
  {
    /*-------------------------------------------------
    The floating point comparisons are imprecise, but the
    user shouldn't be specifying ridiculous constants.
    -------------------------------------------------*/
    if ( ( channel < NUM_OPTIONS ) && ( scale >= 0.0f ) && ( scale <= 1.0f ) )
    {
      pwmScalingConstants[ channel ] = scale;
    }
  }
}  // namespace Luminary::Hardware::PWM
