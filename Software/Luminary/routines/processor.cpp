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
#include <Luminary/hardware/pwm_output.hpp>
#include <Luminary/routines/animation_breath.hpp>
#include <Luminary/routines/animation_default.hpp>
#include <Luminary/routines/animation_flame.hpp>
#include <Luminary/routines/animation_sine_wave.hpp>
#include <Luminary/routines/animation_twinkle.hpp>
#include <Luminary/routines/processor.hpp>
#include <Luminary/routines/types.hpp>

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
    sProcCB.currentAnimation = Registry::SLOT_DEFAULT;
    sProcCB.slots.fill( nullptr );

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
    registerAnimation( SLOT_DEFAULT, &SineWave::animations );

    Flame::construct();
    registerAnimation( SLOT_0, &Flame::animations );

    SineWave::construct();
    registerAnimation( SLOT_1, &SineWave::animations );

    Twinkle::construct();
    registerAnimation( SLOT_2, &Twinkle::animations );

    Breath::construct();
    registerAnimation( SLOT_3, &Breath::animations );

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
    
    AnimationSet* currentSlot = nullptr;
    PWMPercentOut_t updateVal = 0;
    AnimationCB *animation    = nullptr;

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
    Determine if it's safe to execute the animation set
    -------------------------------------------------*/
    if ( ( sProcCB.currentAnimation < Registry::NUM_OPTIONS ) && sProcCB.slots[ sProcCB.currentAnimation ] )
    {
      currentSlot = sProcCB.slots[ sProcCB.currentAnimation ];
    }

    /*-------------------------------------------------
    Run the animation sequence
    -------------------------------------------------*/
    if( currentSlot )
    {
      for ( auto idx = 0; idx < Channel::NUM_OPTIONS; idx++ )
      {
        animation = &( *currentSlot )[ idx ];

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


  void startAnimations()
  {
    lock();
    sProcCB.isRunning    = true;

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


  void setCurrentAnimation( const Registry slot )
  {
    lock();
    sProcCB.currentAnimation = slot;
    unlock();
  }


  void registerAnimation( const Registry slot, AnimationSet *animation )
  {
    lock();

    if( slot < Registry::NUM_OPTIONS )
    {
      sProcCB.slots[ slot ] = animation;
    }

    unlock();
  }
}    // namespace Luminary::Routine
