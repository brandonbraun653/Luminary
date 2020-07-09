/********************************************************************************
 *  File Name:
 *    rcp_responder.cpp
 *
 *  Description:
 *    Implementation of various responses to RPC commands
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstring>

/* Chimera Includes */
#include <Chimera/common>

/* Luminary Includes */
#include <Luminary/model/mdl_observables.hpp>
#include <Luminary/rpc/rpc_responder.hpp>
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  /*-------------------------------------------------------------------------------
  Generic Response Function Definitions
  -------------------------------------------------------------------------------*/
  size_t ackResponse( MessageBuffer &message, const CommandID cmd )
  {
    message.fill( 0 );
    snprintf( reinterpret_cast<char *>( message.data() ), message.size(), "@R:ACK:%d~", static_cast<size_t>( cmd ) );
    return strlen( reinterpret_cast<char *>( message.data() ) );
  }


  size_t nackResponse( MessageBuffer &message, const CommandID cmd )
  {
    message.fill( 0 );
    snprintf( reinterpret_cast<char *>( message.data() ), message.size(), "@R:NACK:%d~", static_cast<size_t>( cmd ) );
    return strlen( reinterpret_cast<char *>( message.data() ) );
  }


  size_t unknownResponse( MessageBuffer &message )
  {
    message.fill( 0 );
    snprintf( reinterpret_cast<char *>( message.data() ), message.size(), "@R:NACK:Unknown Command~" );
    return strlen( reinterpret_cast<char *>( message.data() ) );
  }


  size_t unregisteredResponse( MessageBuffer &message )
  {
    message.fill( 0 );
    snprintf( reinterpret_cast<char *>( message.data() ), message.size(), "@R:NACK:Unregistered Command~" );
    return strlen( reinterpret_cast<char *>( message.data() ) );
  }


  size_t invalidHandlerResponse( MessageBuffer &message )
  {
    message.fill( 0 );
    snprintf( reinterpret_cast<char *>( message.data() ), message.size(), "@R:NACK:Invalid Handler~" );
    return strlen( reinterpret_cast<char *>( message.data() ) );
  }

}    // namespace Luminary::RPC
