/********************************************************************************
 *  File Name:
 *    sys_command.cpp
 *
 *  Description:
 *    System command implementation
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstring>

/* RF24 Includes */
#include <RF24Node/common>
#include <RF24Node/network>

/* Luminary Includes */
#include <Luminary/logging/log_main.hpp>
#include <Luminary/networking/net_main.hpp>
#include <Luminary/networking/types.hpp>
#include <Luminary/routines/processor.hpp>
#include <Luminary/system/sys_command.hpp>

namespace Luminary::System
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void setGlobalAnimation( const Routine::Registry animationID )
  {
    /*-------------------------------------------------
    Obtain needed object references
    -------------------------------------------------*/
    auto radio = Network::getRadio();
    auto logger = Logging::getSystemLogger();

    /*-------------------------------------------------
    Get a reference to the radio and find out it's state
    -------------------------------------------------*/
    RF24::Endpoint::SystemState radioState = radio->getCurrentState();

    /*-------------------------------------------------
    For each child that this node is connected to, send
    the animation change message.
    -------------------------------------------------*/
    static constexpr size_t iterFirst = static_cast<size_t>( RF24::Connection::BindSite::CHILD_1 );
    static constexpr size_t iterLast = static_cast<size_t>( RF24::Connection::BindSite::CHILD_5 );

    for( size_t child = iterFirst; child <= iterLast; child++ )
    {
      auto currentNode = radioState.connectedNodes[ child ];
      if( currentNode == RF24::Network::RSVD_ADDR_INVALID )
      {
        continue;
      }

      setNodeAnimation( currentNode, animationID );
      Chimera::delayMilliseconds( 150 );
    }

    /*-------------------------------------------------
    Update this node's animation
    -------------------------------------------------*/
    Routine::setCurrentAnimation( animationID );
  }


  void setNodeAnimation( const RF24::LogicalAddress address, const Routine::Registry animationID )
  {
    /*-------------------------------------------------
    Obtain needed object references
    -------------------------------------------------*/
    auto radio = Network::getRadio();
    auto logger = Logging::getSystemLogger();

    /*-------------------------------------------------
    Build up the message to be sent out
    -------------------------------------------------*/
    Network::Msg_ChangeAnimation msg;
    memset( &msg, 0, sizeof( Network::Msg_ChangeAnimation ) );

    msg.header.flags |= Network::ControlBits::PropagateToChildren;
    msg.header.messageType = Network::MessageType::CHANGE_ANIMATION;

    msg.animationId = animationID;
    msg.timeout     = 0;

    /*-------------------------------------------------
    Send away!
    -------------------------------------------------*/
    auto err = radio->write( address, &msg, sizeof( msg ) );
    if ( err != Chimera::CommonStatusCodes::OK )
    {
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Failed pushing animation commmand to node [%04o]\n", Chimera::millis(), address );
    }
  }


}  // namespace Luminary::System
