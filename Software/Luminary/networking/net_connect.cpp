/********************************************************************************
 *  File Name:
 *    net_connect.cpp
 *
 *  Description:
 *    Handles network connection details for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>

/* uLog Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_intf.hpp>

/* RF24 Includes */
#include <RF24Node/common>
#include <RF24Node/endpoint>

/* Luminary Includes */
#include <Luminary/hardware/status_led.hpp>
#include <Luminary/networking/net_connect.hpp>
#include <Luminary/networking/net_main.hpp>

namespace Luminary::Network
{
  static RF24::Connection::Result connectStatus;
  void onConnectCallback( const RF24::Connection::Result result, const RF24::Connection::BindSite id )
  {
    auto logger = uLog::getRootSink();
    connectStatus = result;

    if( result == RF24::Connection::Result::CONNECT_PROC_SUCCESS )
    {
      Hardware::StatusLED::updateStatus(Hardware::StatusLED::BlinkPattern::NETWORK_CONNECTED);
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Connect to network success\n", Chimera::millis() );
    }
    else
    {
      Hardware::StatusLED::updateStatus(Hardware::StatusLED::BlinkPattern::NETWORK_DISCONNECTED);
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Connect to network failure\n", Chimera::millis() );
    }
  }


  bool connect()
  {
    auto radio    = getRadio();
    connectStatus = RF24::Connection::Result::CONNECT_PROC_UNKNOWN;

    Hardware::StatusLED::updateStatus(Hardware::StatusLED::BlinkPattern::NETWORK_CONNECTING);
    radio->connectAsync( onConnectCallback, 10000 );

    while ( connectStatus == RF24::Connection::Result::CONNECT_PROC_UNKNOWN )
    {
      radio->processNetworking();
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }

    return connectStatus == RF24::Connection::Result::CONNECT_PROC_SUCCESS;
  }


  void doReconnect()
  {
    auto radio  = getRadio();
    auto logger = uLog::getRootSink();

    logger->flog( uLog::Level::LVL_INFO, "%d-APP: Network timeout. Trying to reconnect...\n", Chimera::millis() );

    Hardware::StatusLED::updateStatus(Hardware::StatusLED::BlinkPattern::NETWORK_CONNECTING);
    connectStatus = RF24::Connection::Result::CONNECT_PROC_UNKNOWN;
    radio->reconnect( onConnectCallback, 10000 );

    while ( connectStatus == RF24::Connection::Result::CONNECT_PROC_UNKNOWN )
    {
      radio->processNetworking();
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }


}  // namespace Luminary::Network
