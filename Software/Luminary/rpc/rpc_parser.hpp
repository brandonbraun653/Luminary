/********************************************************************************
 *  File Name:
 *    rpc_parser.hpp
 *
 *  Description:
 *    Parsing functions for the RPC system
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_RPC_PARSER_HPP
#define LUMINARY_RPC_PARSER_HPP

/* Luminary Includes */
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  /**
   *  Initializes the parser data
   *  @return void
   */
  void initializeParser();

  /**
   *  Parses a command into some sort of action. If a response is required, then
   *  the message buffer will be modified appropriately and the number of bytes
   *  to be sent is returned.
   *
   *  @param[in]  message     The message to be parsed
   *  @return size_t
   */
  size_t parseCommand( MessageBuffer &message );

}  // namespace Luminary::RPC

#endif  /* !LUMINARY_RPC_PARSER_HPP */
