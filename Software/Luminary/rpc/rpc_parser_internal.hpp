/********************************************************************************
 *  File Name:
 *    rpc_parser_internal.hpp
 *
 *  Description:
 *    Internal use functions for the RPC system
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_RPC_PARSER_INTERNAL_HPP
#define LUMINARY_RPC_PARSER_INTERNAL_HPP

/* Luminary Includes */
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC::Internal
{
  /**
   *  Gets the type of command present in the string
   *
   *  @param[in]  s   The string which contains the command sequence
   *  @return CommandPrefix
   */
  CommandPrefix extractCommandType( std::string_view s );

  /**
   *  Gets the data attached to the command
   *
   *  @param[in]  s   The string which contains the command sequence
   *  @return std::string_view
   */
  std::string_view extractCommandData( std::string_view s );

  /**
   *  Pulls out the command to be invoked
   *
   *  @param[in]  s   The string which contains the command sequence
   *  @return CommandID
   */
  CommandID extractCommandID( std::string_view s );

}  // namespace Luminary::RPC

#endif  /* !LUMINARY_RPC_PARSER_INTERNAL_HPP */
