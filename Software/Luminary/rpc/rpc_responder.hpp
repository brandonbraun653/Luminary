/********************************************************************************
 *  File Name:
 *    rpc_responder.hpp
 *
 *  Description:
 *    Interface for responses to commands in the RPC processing
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_RPC_RESPONSES_HPP
#define LUMINARY_RPC_RESPONSES_HPP

/* STL Includes */
#include <cstddef>

/* Luminary Includes */
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  /*-------------------------------------------------------------------------------
  Generic Response Function Declarations
  -------------------------------------------------------------------------------*/
  /**
   *  Generates an ACK response in the given message buffer
   *
   *  @note Used when something succeeded and the remote caller needs to know
   *
   *  @param[out] message     The buffer to generate the response in
   *  @param[in]  cmd         Which command is being acked
   *  @return size_t          Number of bytes in the formatted output
   */
  size_t ackResponse( MessageBuffer &message, const CommandID cmd );

  /**
   *  Generates a NACK response in the given message buffer
   *
   *  @note Used when something failed and the remote caller needs to know
   *
   *  @param[out] message     The buffer to generate the response in
   *  @param[in]  cmd         Which command is being nacked
   *  @return size_t          Number of bytes in the formatted output
   */
  size_t nackResponse( MessageBuffer &message, const CommandID cmd );

  /**
   *  Generates a unknown message response in the given message buffer
   *
   *  @note Used when a requested command is unknown to the system
   *
   *  @param[out] message     The buffer to generate the response in
   *  @return size_t          Number of bytes in the formatted output
   */
  size_t unknownResponse( MessageBuffer &message );

  /**
   *  Generates a unregistered message response in the given message buffer
   *
   *  @note Used when a command is valid but there is no registered action
   *
   *  @param[out] message     The buffer to generate the response in
   *  @return size_t          Number of bytes in the formatted output
   */
  size_t unregisteredResponse( MessageBuffer &message );

  
  /**
   *  Generates a bad handler message response in the given message buffer
   *
   *  @note Used when an improper handler is used on a command
   *
   *  @param[out] message     The buffer to generate the response in
   *  @return size_t          Number of bytes in the formatted output
   */
  size_t invalidHandlerResponse( MessageBuffer &message );
  

  /*-------------------------------------------------------------------------------
  Command Response Function Definitions
  -------------------------------------------------------------------------------*/
  /**
   *  Command support for:
   *    CMD_ID_TURN_OUTPUT_ON
   *    CMD_ID_TURN_OUTPUT_OFF
   *
   *  @param[out] message     The buffer to generate the response in
   *  @param[in]  cmd         Which command is being invoked
   *  @return size_t          Number of bytes in the formatted output
   */
  size_t actionSetOutputState( MessageBuffer &message, const CommandID cmd );

}  // namespace Luminary::RPC

#endif  /* !LUMINARY_RPC_RESPONSES_HPP */
