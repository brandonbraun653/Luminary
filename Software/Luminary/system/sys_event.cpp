/********************************************************************************
 *  File Name:
 *    sys_event.cpp
 *
 *  Description:
 *    System event implementation
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* uLog Includes */
#include <uLog/ulog.hpp>

/* Luminary Includes */
#include <Luminary/networking/types.hpp>
#include <Luminary/routines/processor.hpp>
#include <Luminary/routines/types.hpp>
#include <Luminary/system/sys_event.hpp>

namespace Luminary::System
{
  EventCallbackList eventCallbacks;

  void registerEventCallbacks()
  {
    eventCallbacks.fill( nullptr );

    eventCallbacks[ Network::MessageType::CHANGE_ANIMATION ]  = changeAnimationHandler;
    eventCallbacks[ Network::MessageType::CHANGE_BRIGHTNESS ] = changeBrightnessHandler;
  }


  void changeAnimationHandler( const uint8_t msg, void *data )
  {
    using namespace Luminary::Network;

    /*-------------------------------------------------
    Sanity check the input
    -------------------------------------------------*/
    if ( !data || ( msg != Network::CHANGE_ANIMATION ) )
    {
      return;
    }

    /*-------------------------------------------------
    Pull out the needed data and invoke the animation change
    -------------------------------------------------*/
    auto packet = reinterpret_cast<Msg_ChangeAnimation *>( data );

    if( packet->animationId < Routine::Registry::NUM_OPTIONS )
    {
      Routine::setCurrentAnimation( packet->animationId );


      uLog::getRootSink()->flog( uLog::Level::LVL_INFO, "%d-APP: Got request to change animation to slot-%d\n",
                                 Chimera::millis(), packet->animationId );
    }
  }

  void changeBrightnessHandler( const uint8_t msg, void *data )
  {
  }

}    // namespace Luminary::System
