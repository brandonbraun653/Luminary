/********************************************************************************
 *  File Name:
 *    rpc_parser.cpp
 *
 *  Description:
 *    Implementation details of the RPC parser
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>
#include <charconv>
#include <cstring>
#include <string>

/* Aurora Includes */
#include "ctre.hpp"

/* Luminary Includes */
#include <Luminary/rpc/rpc_parser.hpp>
#include <Luminary/rpc/rpc_responder.hpp>
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  // List of all supported commands
  static CommandList sCommands;
  static CommandType sCmdType;

  // Regex matcher for matching supported commands
  static std::string commandMatcher      = "@([I,Q]{1}):(.*)~.*";
  static constexpr size_t commandCaptureGroup = 1;
  static constexpr size_t dataCaptureGroup    = 2;


  static const char *invokeIDSubMatcher = "[0-9]{1,3}";

  /**
   *
   */
  static CommandPrefix extractCommandType( std::string_view s );

  static std::string_view extractCommandData( std::string_view s );

  /**
   *  Pulls out the command to be invoked
   *
   *  @param[in]  s   The string which contains the command sequence
   *  @return size_t
   */
  static size_t extractCommandNumber( std::string_view s );


  void initializeParser()
  {
    /*------------------------------------------------
    Register all the supported commands with the system
    ------------------------------------------------*/
    for ( auto x = 0; x < sCommands.size(); x++ )
    {
      sCommands[ x ] = {};
      sCommands[ x ].clear();
    }

    
    sCommands[ CMD_ID_TURN_OUTPUT_ON ].setName( "OUTPUT_ON" );
    sCommands[ CMD_ID_TURN_OUTPUT_ON ].action = actionSetOutputState;

    sCommands[ CMD_ID_TURN_OUTPUT_OFF ].setName( "OUTPUT_OFF" );
    sCommands[ CMD_ID_TURN_OUTPUT_OFF ].action = actionSetOutputState;
  }


  size_t parseCommand( MessageBuffer &message )
  {
    /*------------------------------------------------
    Figure out which command is desired to be invoked
    ------------------------------------------------*/
    std::string_view dataField = extractCommandData( reinterpret_cast<char *>( message.data() ) );

    switch( extractCommandType( reinterpret_cast<char *>( message.data() ) ) )
    {
      case CMD_PFX_INVOKE:
        {
          auto lookup = extractCommandNumber( dataField );
          if ( lookup >= sCommands.size() )
          {
            return unknownResponse( message );
          }
          else if ( !sCommands[ lookup ].action )
          {
            return unregisteredResponse( message );
          }

          /*------------------------------------------------
          Invoke the command and handle any responses
          ------------------------------------------------*/
          return sCommands[ lookup ].action( message, static_cast<CommandID>( lookup ) );
        }
        break;

      case CMD_PFX_QUERY:
        {
          return unknownResponse( message );
        }

      case CMD_PFX_INVALID:
      default:
        return unknownResponse( message );
        break;
    }

  }


  static CommandPrefix extractCommandType( std::string_view s )
  {

    auto result  = CommandPrefix::CMD_PFX_INVALID;

    if( auto matchList = ctre::match<"@([I,Q]{1}):(.*)~.*">( s ) )
    {
      auto view = matchList.get<commandCaptureGroup>().to_view();

      if( view == QueryCommand )
      {
        result = CommandPrefix::CMD_PFX_QUERY;
      }
      else if( view == InvokeCommand )
      {
        result = CommandPrefix::CMD_PFX_INVOKE;
      }
    }

    return result;
  }


  static std::string_view extractCommandData( std::string_view s )
  {
    if( auto matchList = ctre::match<"@([I,Q]{1}):(.*)~.*">( s ) )
    {
      return matchList.get<dataCaptureGroup>().to_view();
    }

    return {};
  }


  static size_t extractCommandNumber( std::string_view s )
  {
    size_t result  = CMD_ID_INVALID;
    auto matchList = ctre::match<"([0-9]{1,3}).*">( s );

    if ( matchList )
    {
      /*------------------------------------------------
      Pull out the expected capture group in the matcher, which
      contains the command number, and parse it to an integer.
      ------------------------------------------------*/
      auto match      = matchList.get<0>().to_view();
      int number      = -1;
      auto conversion = std::from_chars( match.begin(), match.end(), number );

      /*------------------------------------------------
      No conversion issues and number falls in the correct range
      ------------------------------------------------*/
      if ( ( number >= 0 ) && ( number < sCommands.size() ) && ( conversion.ec != std::errc::invalid_argument ))
      {
        result = static_cast<size_t>( number );
      }
    }

    return result;
  }

}    // namespace Luminary::RPC
