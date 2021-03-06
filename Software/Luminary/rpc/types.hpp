/********************************************************************************
 *  File Name:
 *    types.hpp
 *
 *  Description:
 *    Types used in the RPC processing
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_RPC_TYPES_HPP
#define LUMINARY_RPC_TYPES_HPP

/* STL Includes */
#include <array>
#include <cstddef>
#include <cstring>

/* Boost Includes */
#include <boost/circular_buffer_fwd.hpp>

namespace Luminary::RPC
{
  /*-------------------------------------------------------------------------------
  Forward Declarations
  -------------------------------------------------------------------------------*/
  class CommandRegistry;

  /*-------------------------------------------------------------------------------
  Configuration Variables
  -------------------------------------------------------------------------------*/
  // Length of the string that can invoke a command
  static constexpr size_t MaxCommandLength = 16;

  // Length of the hardware buffer for transceiving a Serial message
  static constexpr size_t MaxMessageSize = 50;

  // Command character set
  static std::string_view StartCharacter = "@";
  static std::string_view QueryCommand   = "Q";
  static std::string_view InvokeCommand  = "I";
  static std::string_view DataDelimiter  = ":";
  static std::string_view EndCharacter   = "~";

  /*-------------------------------------------------------------------------------
  Enums
  -------------------------------------------------------------------------------*/
  /**
   *  Supported command prefix identifiers (lookup table)
   */
  enum CommandPrefix : size_t
  {
    CMD_PFX_INVOKE, /**< Invoke a command to be performed */
    CMD_PFX_QUERY,  /**< Ask some kind of question */

    CMD_PFX_NUM_OPTIONS,
    CMD_PFX_INVALID,
    CMD_PFX_BEGIN = CMD_PFX_INVOKE,
    CMD_PFX_END = CMD_PFX_NUM_OPTIONS
  };


  /**
   *  Suported commands that can be invoked
   */
  enum CommandID : size_t
  {
    CMD_ID_TURN_OUTPUT_ON,          /**< Turns a specific output on */
    CMD_ID_TURN_OUTPUT_OFF,         /**< Turns a specific output off */
    CMD_ID_SET_ANIMATION_GLOBAL,    /**< Sets the animation for the entire network */
    CMD_ID_SET_ANIMATION_DEVICE,    /**< Sets the animation on a particular device */
    CMD_ID_SET_BRIGHTNESS_RELATIVE, /**< Sets the brightness relative to current */
    CMD_ID_SET_BRIGHTNESS_ABSOLUTE, /**< Sets the brightness absolutely */

    CMD_ID_NUM_OPTIONS,
    CMD_ID_INVALID,
    CMD_ID_BEGIN = CMD_ID_TURN_OUTPUT_ON,
    CMD_ID_END = CMD_ID_NUM_OPTIONS
  };

  enum QuestionID : size_t
  {
    // Put question types here

    QID_NUM_OPTIONS,
    QID_INVALID,
    QID_BEGIN = 0,
    QID_END = QID_BEGIN
  };

  /*-------------------------------------------------------------------------------
  Aliases
  -------------------------------------------------------------------------------*/
  using MessageBuffer = std::array<uint8_t, MaxMessageSize>;
  using CommandList   = std::array<CommandRegistry, static_cast<size_t>( CMD_ID_NUM_OPTIONS )>;
  using CommandName   = std::array<char, MaxCommandLength>;
  using CommandType   = std::array<CommandName, static_cast<size_t>( CMD_PFX_NUM_OPTIONS )>;


  /*-------------------------------------------------------------------------------
  Classes
  -------------------------------------------------------------------------------*/
  /**
   *  Wraps a function that should be invoked upon some kind of command
   */
  class CommandRegistry
  {
  public:
    CommandID id; /**< Lookup ID associated with this command */

    /**
     *  Function pointer to invoke an action associated with this command
     *
     *  @param[in]  msg     Message that was received
     *  @param[in]  cmd     Identifier of the command that was received
     *  @return size_t      Number of bytes in the return message, if any
     */
    size_t ( *action )( MessageBuffer &msg, const CommandID cmd );

    /**
     *  Assigns a name to the command
     *
     *  @param[in]  string    The string that will be the command name
     *  @return void
     */
    void setName( std::string_view string )
    {
      name.fill( 0 );

      const size_t strLen   = string.length();
      const size_t maxBytes = ( strLen > name.size() ) ? name.size() : string.length();

      memcpy( name.data(), string.data(), maxBytes );
    }

    /**
     *  Gets the name associated with the command
     *  @return std::string_view
     */
    std::string_view getName()
    {
      return std::string_view( name.data() );
    }

    /**
     *  Initializes the command data to defaults
     *  @return void
     */
    void clear()
    {
      name.fill( 0 );
      action = nullptr;
      id     = CommandID::CMD_ID_INVALID;
    }

  private:
    CommandName name;
  };

}    // namespace Luminary::RPC

#endif /* !LUMINARY_RPC_TYPES_HPP */
