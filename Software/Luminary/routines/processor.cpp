/********************************************************************************
 *  File Name:
 *    processor.cpp
 *
 *  Description:
 *    Animation routine processor
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/routines/processor.hpp>
#include <Luminary/routines/types.hpp>
#include <Luminary/hardware/pwm_output.hpp>
#include <Luminary/routines/animation_default.hpp>
#include <Luminary/routines/animation_sine_wave.hpp>

namespace Luminary::Routine
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  // Global lock on the animation processor
  static Chimera::Threading::RecursiveMutex sProcessLock;

  // Control block for the animation processor
  static ProcessorCB sProcCB;

  /*-------------------------------------------------------------------------------
  Static Function Definitions
  -------------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------------
  Public Function Definition
  -------------------------------------------------------------------------------*/
  void initialize()
  {
    using namespace Hardware::PWM;

    lock();

    /*-------------------------------------------------
    Initialize the procesor system state
    -------------------------------------------------*/
    sProcCB.isRunning = false;

    sProcCB.animations[ Channel::PWM_CH_0 ] = nullptr;
    sProcCB.animations[ Channel::PWM_CH_1 ] = nullptr;
    sProcCB.animations[ Channel::PWM_CH_2 ] = nullptr;

    /*-------------------------------------------------
    Turn off all the outputs
    -------------------------------------------------*/
    Hardware::PWM::setOutputState( Channel::PWM_CH_0, false );
    Hardware::PWM::setOutputState( Channel::PWM_CH_1, false );
    Hardware::PWM::setOutputState( Channel::PWM_CH_2, false );

    /*-------------------------------------------------
    Initialize Animations
    -------------------------------------------------*/
    Default::construct();
    SineWave::construct();

    unlock();
  }


  void lock()
  {
    sProcessLock.lock();
  }


  void unlock()
  {
    sProcessLock.unlock();
  }


  void stepAnimations()
  {
    using namespace Hardware::PWM;

    lock();

    /*-------------------------------------------------
    If we aren't processing, simply exit
    -------------------------------------------------*/
    if ( !sProcCB.isRunning )
    {
      unlock();
      return;
    }

    /*-------------------------------------------------
    If we are running in reversionary mode, simply run the
    default animation and pipe it to all outputs. Otherwise,
    update all outputs with the appropriate state.
    -------------------------------------------------*/
    PWMPercentOut_t updateVal = 0;
    AnimationCB *animation    = nullptr;

    if ( sProcCB.reversionary )
    {
      /*-------------------------------------------------
      No default animation specified, so there is nothing to run
      -------------------------------------------------*/
      if ( !sProcCB.defaultAnimation )
      {
        return;
      }

      /*-------------------------------------------------
      Update every output with the current default value
      -------------------------------------------------*/
      animation = sProcCB.defaultAnimation;

      if ( ( Chimera::millis() - animation->lastTime ) > animation->updateDT )
      {
        updateVal           = animation->update( animation );
        animation->lastTime = Chimera::millis();

        Hardware::PWM::updateDutyCycle( Channel::PWM_CH_0, updateVal );
        Hardware::PWM::updateDutyCycle( Channel::PWM_CH_1, updateVal );
        Hardware::PWM::updateDutyCycle( Channel::PWM_CH_2, updateVal );
      }
    }
    else
    {
      for ( auto idx = 0; idx < Channel::NUM_OPTIONS; idx++ )
      {
        animation = sProcCB.animations[ idx ];

        /*-------------------------------------------------
        Update the output state for the current animation
        -------------------------------------------------*/
        if ( animation && ( ( Chimera::millis() - animation->lastTime ) > animation->updateDT ) )
        {
          updateVal           = animation->update( animation );
          animation->lastTime = Chimera::millis();

          Hardware::PWM::updateDutyCycle( static_cast<Channel>( idx ), updateVal );
        }
      }
    }

    unlock();
  }


  void startAnimations( const bool reversionary )
  {
    lock();
    sProcCB.isRunning    = true;
    sProcCB.reversionary = reversionary;

    /*-------------------------------------------------
    Turn on all the outputs
    -------------------------------------------------*/
    Hardware::PWM::setOutputState( Hardware::PWM::Channel::PWM_CH_0, true );
    Hardware::PWM::setOutputState( Hardware::PWM::Channel::PWM_CH_1, true );
    Hardware::PWM::setOutputState( Hardware::PWM::Channel::PWM_CH_2, true );
    unlock();
  }


  void stopAnimations()
  {
    lock();
    sProcCB.isRunning = false;

    /*-------------------------------------------------
    Turn off all the outputs
    -------------------------------------------------*/
    Hardware::PWM::setOutputState( Hardware::PWM::Channel::PWM_CH_0, false );
    Hardware::PWM::setOutputState( Hardware::PWM::Channel::PWM_CH_1, false );
    Hardware::PWM::setOutputState( Hardware::PWM::Channel::PWM_CH_2, false );
    unlock();
  }


  void setDefaultAnimation( AnimationCB *animation )
  {
    lock();
    sProcCB.defaultAnimation = animation;
    unlock();
  }


  bool setCurrentAnimation( const Hardware::PWM::Channel channel, AnimationCB *animation )
  {
    lock();

    // Need to set some return value

    unlock();

    return false;
  }

}    // namespace Luminary::Routine
