/********************************************************************************
 *  File Name:
 *    types.hpp
 *
 *  Description:
 *    Networking types for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_NETWORKING_TYPES_HPP
#define LUMINARY_NETWORKING_TYPES_HPP

/* STL Includes */
#include <cstdint>
#include <cstddef>

/* RF24Node Includes */
#include <RF24Node/network>

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::Network
{
  /*-------------------------------------------------------------------------------
  Enums
  -------------------------------------------------------------------------------*/
  /**
   *  Describes the kind of message that is being sent across the network
   */
  enum MessageType : uint8_t
  {
    INVALID,

    CHANGE_ANIMATION,   /**< The message handles animation changes */
    CHANGE_BRIGHTNESS,  /**< The message handles brightness chagnes */

    NUM_OPTIONS
  };


  /*-------------------------------------------------------------------------------
  Structures
  -------------------------------------------------------------------------------*/
  /*-------------------------------------------------
  Message Header: Defines several control fields that
  indicate what the message is and what it should do.
  -------------------------------------------------*/
#pragma pack( push )
#pragma pack( 1 )
  struct Msg_Header
  {
    uint8_t messageType;  /**< What kind of message this is */
    uint8_t flags;        /**< Bitfield that controls message behavior */
    uint8_t pad[ 2 ];     /**< Buffer for future expansion */
  };
  static_assert( sizeof( Msg_Header ) == sizeof( uint32_t ) );
#pragma pack( pop )


  /*-------------------------------------------------
  Change Animation: Message type that instructs an
  animation change to occur
  -------------------------------------------------*/
#pragma pack( push )
#pragma pack( 1 )
  struct Msg_ChangeAnimation
  {
    Msg_Header header;              /**< Message header for network level control */
    Routine::Registry animationId;  /**< Which animation to invoke */
    uint32_t timeout;               /**< How long the animation can run */
    uint8_t pad[ 15 ];              /**< Pad for future growth */
  };

  static_assert( sizeof( Msg_ChangeAnimation ) == RF24::Network::Frame::PAYLOAD_SIZE );
#pragma pack( pop )


  /*-------------------------------------------------------------------------------
  Namespaces
  -------------------------------------------------------------------------------*/
  namespace ControlBits
  {
    static constexpr uint8_t PropagateToChildren = ( 1u << 0 );
  }

}  // namespace Luminary::Network

#endif  /* !LUMINARY_NETWORKING_TYPES_HPP */
