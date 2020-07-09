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
#include <Luminary/rpc/rpc_parser_internal.hpp>
#include <Luminary/rpc/rpc_responder.hpp>
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  // List of all supported commands
  static CommandList sCommands;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initializeParser()
  {
    /*------------------------------------------------
    Clear out existing commands
    ------------------------------------------------*/
    for ( size_t x = 0; x < sCommands.size(); x++ )
    {
      sCommands[ x ] = {};
      sCommands[ x ].clear();
    }

    /*------------------------------------------------
    Register all the supported commands with the system
    ------------------------------------------------*/
    sCommands[ CMD_ID_TURN_OUTPUT_ON ].setName( "OUTPUT_ON" );
    sCommands[ CMD_ID_TURN_OUTPUT_ON ].action = actionSetOutputState;
    sCommands[ CMD_ID_TURN_OUTPUT_ON ].id     = CMD_ID_TURN_OUTPUT_ON;

    sCommands[ CMD_ID_TURN_OUTPUT_OFF ].setName( "OUTPUT_OFF" );
    sCommands[ CMD_ID_TURN_OUTPUT_OFF ].action = actionSetOutputState;
    sCommands[ CMD_ID_TURN_OUTPUT_OFF ].id     = CMD_ID_TURN_OUTPUT_OFF;

    sCommands[ CMD_ID_SET_ANIMATION_GLOBAL ].setName( "SET_ANIMATION_GLOBAL" );
    sCommands[ CMD_ID_SET_ANIMATION_GLOBAL ].action = actionSetAnimationGlobal;
    sCommands[ CMD_ID_SET_ANIMATION_GLOBAL ].id     = CMD_ID_SET_ANIMATION_GLOBAL;

    sCommands[ CMD_ID_SET_ANIMATION_DEVICE ].setName( "SET_ANIMATION_DEVICE" );
    sCommands[ CMD_ID_SET_ANIMATION_DEVICE ].action = actionSetAnimationDevice;
    sCommands[ CMD_ID_SET_ANIMATION_DEVICE ].id     = CMD_ID_SET_ANIMATION_DEVICE;

    sCommands[ CMD_ID_SET_BRIGHTNESS_ABSOLUTE ].setName( "SET_BRIGHTNESS_ABSOLUTE" );
    sCommands[ CMD_ID_SET_BRIGHTNESS_ABSOLUTE ].action = actionSetBrightnessAbsolute;
    sCommands[ CMD_ID_SET_BRIGHTNESS_ABSOLUTE ].id     = CMD_ID_SET_BRIGHTNESS_ABSOLUTE;

    sCommands[ CMD_ID_SET_BRIGHTNESS_RELATIVE ].setName( "SET_BRIGHTNESS_RELATIVE" );
    sCommands[ CMD_ID_SET_BRIGHTNESS_RELATIVE ].action = actionSetBrightnessRelative;
    sCommands[ CMD_ID_SET_BRIGHTNESS_RELATIVE ].id     = CMD_ID_SET_BRIGHTNESS_RELATIVE;
  }


  size_t parseCommand( MessageBuffer &message )
  {
    /*------------------------------------------------
    Figure out which command is desired to be invoked
    ------------------------------------------------*/
    std::string_view dataField = Internal::extractCommandData( reinterpret_cast<char *>( message.data() ) );

    switch ( Internal::extractCommandType( reinterpret_cast<char *>( message.data() ) ) )
    {
      /*-------------------------------------------------
      The command will invoke some kind of action
      -------------------------------------------------*/
      case CMD_PFX_INVOKE:
      {
        /*-------------------------------------------------
        Determine the command identifier
        -------------------------------------------------*/
        auto lookup = Internal::extractCommandID( dataField );
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

      /*-------------------------------------------------
      The command asks some kind of question
      -------------------------------------------------*/
      case CMD_PFX_QUERY:
      {
        return unknownResponse( message );
      }

      /*-------------------------------------------------
      The command is unsupported
      -------------------------------------------------*/
      case CMD_PFX_INVALID:
      default:
        return unknownResponse( message );
        break;
    }
  }


  /*-------------------------------------------------------------------------------
  Internal Functions
  -------------------------------------------------------------------------------*/
  namespace Internal
  {
    CommandPrefix extractCommandType( std::string_view s )
    {
      auto result = CommandPrefix::CMD_PFX_INVALID;

      /*-------------------------------------------------
      Try and match the string with the expected sequence
      -------------------------------------------------*/
      if ( auto matchList = ctre::match<"@([I,Q]{1}):(.*)~.*">( s ) )
      {
        static constexpr size_t typeCaptureGroup = 1;
        auto view                                = matchList.get<typeCaptureGroup>().to_view();

        /*-------------------------------------------------
        Getting here means something matched. Figure out
        which command it is.
        -------------------------------------------------*/
        if ( view == QueryCommand )
        {
          result = CommandPrefix::CMD_PFX_QUERY;
        }
        else if ( view == InvokeCommand )
        {
          result = CommandPrefix::CMD_PFX_INVOKE;
        }
      }

      return result;
    }


    std::string_view extractCommandData( std::string_view s )
    {
      /*-------------------------------------------------
      Return whatever the 2nd capture group matches
      -------------------------------------------------*/
      if ( auto matchList = ctre::match<"@([I,Q]{1}):(.*)~.*">( s ) )
      {
        static constexpr size_t dataCaptureGroup = 2;
        return matchList.get<dataCaptureGroup>().to_view();
      }

      /*-------------------------------------------------
      Nothing matched? Give back an empty string view.
      -------------------------------------------------*/
      return {};
    }


    CommandID extractCommandID( std::string_view s )
    {
      CommandID result = CMD_ID_INVALID;

      if ( auto matchList = ctre::match<".*([0-9]{1,3}).*">( s ) )
      {
        static constexpr size_t cmdCaptureGroup = 1;

        /*------------------------------------------------
        Pull out the expected capture group in the matcher, which
        contains the command number, and parse it to an integer.
        ------------------------------------------------*/
        std::string_view match      = matchList.get<cmdCaptureGroup>().to_view();
        int number      = -1;
        auto conversion = std::from_chars( match.data(), match.data() + match.size(), number );

        /*------------------------------------------------
        No conversion issues and number falls in the correct range
        ------------------------------------------------*/
        if ( ( number >= 0 ) && ( number < static_cast<int>( sCommands.size() ) ) &&
             ( conversion.ec != std::errc::invalid_argument ) )
        {
          result = static_cast<CommandID>( number );
        }
      }

      return result;
    }
  }    // namespace Internal

}    // namespace Luminary::RPC
