/********************************************************************************
 *  File Name:
 *    test_rpc_parser.cpp
 *
 *  Description:
 *    Tests the RPC parser
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <vector>

/* Google Includes */
#include <gtest/gtest.h>

/* Luminary Includes */
#include <Luminary/rpc/rpc_parser.hpp>
#include <Luminary/rpc/rpc_parser_internal.hpp>

/* Formatting Includes */
#include <fmt/core.h>

/*-------------------------------------------------------------------------------
Test extractCommandType()
-------------------------------------------------------------------------------*/
struct DataSet_CommandType
{
  std::string command;
  Luminary::RPC::CommandPrefix expected;
};

TEST( CommandExtraction, ValidCommandTypes )
{
  using namespace Luminary::RPC;

  /*------------------------------------------------
  Generate a command list
  ------------------------------------------------*/
  std::vector<DataSet_CommandType> testSet;

  // Valid Invoke Commands
  for ( size_t id = CMD_ID_BEGIN; id < CMD_ID_END; id++ )
  {
    DataSet_CommandType tmp;
    tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, id, EndCharacter );
    tmp.expected = CommandPrefix::CMD_PFX_INVOKE;

    testSet.push_back( tmp );
  }

  // Valid Query Commands
  for ( size_t id = QID_BEGIN; id < QID_END; id++ )
  {
    DataSet_CommandType tmp;
    tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, QueryCommand, DataDelimiter, id, EndCharacter );
    tmp.expected = CommandPrefix::CMD_PFX_QUERY;

    testSet.push_back( tmp );
  }

  /*------------------------------------------------
  Iterate over each test combination
  ------------------------------------------------*/
  for ( auto test : testSet )
  {
    auto actual = Internal::extractCommandType( test.command );
    EXPECT_EQ( actual, test.expected ) << fmt::format( "Test failed on command: {}", test.command );
  }
}

TEST( CommandExtraction, InvalidCommands )
{
  using namespace Luminary::RPC;

  /*------------------------------------------------
  Generate a command list
  ------------------------------------------------*/
  DataSet_CommandType tmp;
  std::vector<DataSet_CommandType> testSet;

  // Bad start character
  tmp.command = fmt::format( "{}{}{}{}{}", "-", InvokeCommand, DataDelimiter, 0, EndCharacter );
  tmp.expected = CommandPrefix::CMD_PFX_INVALID;
  testSet.push_back( tmp );

  // Bad command prefix
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, "Z", DataDelimiter, 0, EndCharacter );
  tmp.expected = CommandPrefix::CMD_PFX_INVALID;
  testSet.push_back( tmp );

  // Bad data delimiter
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, QueryCommand, "2", 0, EndCharacter );
  tmp.expected = CommandPrefix::CMD_PFX_INVALID;
  testSet.push_back( tmp );

  // Bad end character
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, QueryCommand, DataDelimiter, 0, "`" );
  tmp.expected = CommandPrefix::CMD_PFX_INVALID;
  testSet.push_back( tmp );

  /*------------------------------------------------
  Iterate over each test combination
  ------------------------------------------------*/
  for ( auto test : testSet )
  {
    auto actual = Internal::extractCommandType( test.command );
    EXPECT_EQ( actual, test.expected ) << fmt::format( "Test failed on command: {}", test.command );
  }
}


/*-------------------------------------------------------------------------------
Test extractCommandData()
-------------------------------------------------------------------------------*/
struct DataSet_CommandData
{
  std::string command;
  std::string expected;
};

TEST( CommandExtraction, ValidData )
{
  using namespace Luminary::RPC;

  /*------------------------------------------------
  Generate a command list
  ------------------------------------------------*/
  std::vector<DataSet_CommandData> testSet;


  for ( size_t data = 0; data < 20; data++ )
  {
    DataSet_CommandData tmp;
    tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, data, EndCharacter );
    tmp.expected = fmt::format( "{}", data );

    testSet.push_back( tmp );
  }

  /*------------------------------------------------
  Iterate over each test combination
  ------------------------------------------------*/
  for ( auto test : testSet )
  {
    auto actual = Internal::extractCommandData( test.command );
    EXPECT_EQ( actual, test.expected ) << fmt::format( "Test failed on command: {}", test.command );
  }
}

TEST( CommandExtraction, InvalidData )
{
  using namespace Luminary::RPC;

  /*------------------------------------------------
  Generate a command list
  ------------------------------------------------*/
  DataSet_CommandData tmp;
  std::vector<DataSet_CommandData> testSet;

  // Bad start character
  tmp.command = fmt::format( "{}{}{}{}{}", "-", InvokeCommand, DataDelimiter, 0, EndCharacter );
  tmp.expected = {};
  testSet.push_back( tmp );

  // Bad command prefix
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, "Z", DataDelimiter, 0, EndCharacter );
  tmp.expected = {};
  testSet.push_back( tmp );

  // Bad data delimiter
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, QueryCommand, "2", 0, EndCharacter );
  tmp.expected = {};
  testSet.push_back( tmp );

  // Bad end character
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, QueryCommand, DataDelimiter, 0, "`" );
  tmp.expected = {};
  testSet.push_back( tmp );

  /*------------------------------------------------
  Iterate over each test combination
  ------------------------------------------------*/
  std::string_view emptyString = {};

  for ( auto test : testSet )
  {
    auto actual = Internal::extractCommandData( test.command );
    EXPECT_EQ( actual, emptyString ) << fmt::format( "Test failed on command: {}", test.command );
  }
}


/*-------------------------------------------------------------------------------
Test extractCommandID()
-------------------------------------------------------------------------------*/
struct DataSet_CommandID
{
  std::string command;
  Luminary::RPC::CommandID expected;
};

TEST( CommandExtraction, ValidCommandID )
{
  using namespace Luminary::RPC;

  /*------------------------------------------------
  Generate a command list
  ------------------------------------------------*/
  DataSet_CommandID tmp;
  std::vector<DataSet_CommandID> testSet;

  // Valid Invoke Commands
  for ( size_t id = CMD_ID_BEGIN; id < CMD_ID_END; id++ )
  {
    tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, id, EndCharacter );
    tmp.expected = static_cast<CommandID>( id );

    testSet.push_back( tmp );
  }

  /*------------------------------------------------
  Iterate over each test combination
  ------------------------------------------------*/
  for ( auto test : testSet )
  {
    auto actual = Internal::extractCommandID( test.command );
    EXPECT_EQ( actual, test.expected ) << fmt::format( "Test failed on command: {}", test.command );
  }
}

TEST( CommandExtraction, InvalidCommandID )
{
  using namespace Luminary::RPC;

  /*------------------------------------------------
  Generate a command list
  ------------------------------------------------*/
  DataSet_CommandID tmp;
  std::vector<DataSet_CommandID> testSet;
  
  // Upper bound of the matcher regex, but still invalid command
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, 999, EndCharacter );
  tmp.expected = CommandID::CMD_ID_INVALID;

  // Out of bounds for matcher regex
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, 1000, EndCharacter );
  tmp.expected = CommandID::CMD_ID_INVALID;

  // Out of bounds for matcher regex, no data field present
  tmp.command = fmt::format( "{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, EndCharacter );
  tmp.expected = CommandID::CMD_ID_INVALID;

  // Just one outside the valid command range
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, CommandID::CMD_ID_END, EndCharacter );
  tmp.expected = CommandID::CMD_ID_INVALID;

  // Negative numbers
  tmp.command = fmt::format( "{}{}{}{}{}", StartCharacter, InvokeCommand, DataDelimiter, -1, EndCharacter );
  tmp.expected = CommandID::CMD_ID_INVALID;

  /*------------------------------------------------
  Iterate over each test combination
  ------------------------------------------------*/
  for ( auto test : testSet )
  {
    auto actual = Internal::extractCommandID( test.command );
    EXPECT_EQ( actual, test.expected ) << fmt::format( "Test failed on command: {}", test.command );
  }
}


/*-------------------------------------------------------------------------------
Test parseCommand()
-------------------------------------------------------------------------------*/
struct DataSet_CommandParse
{

};

TEST( CommandParsing, ValidCommand )
{
 EXPECT_EQ( false, true );
}

TEST( CommandParsing, UnknownCommand )
{
 EXPECT_EQ( false, true );
}

TEST( CommandParsing, UnregisteredCommand )
{
 EXPECT_EQ( false, true );
}