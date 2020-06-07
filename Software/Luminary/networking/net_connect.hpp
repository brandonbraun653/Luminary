/********************************************************************************
 *  File Name:
 *    net_connect.hpp
 *
 *  Description:
 *    Network connection operations for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_NETWORK_CONNECTION_HPP
#define LUMINARY_NETWORK_CONNECTION_HPP

/* Chimera Includes */
#include <Chimera/common>

namespace Luminary::Network
{
  /**
   *  Connects the device to the network
   *
   *  @return bool    True if successful, false if not
   */
  bool connect();

  /**
   *  Invokes a state machine that reconnects the node to the network
   */
  void doReconnect();

}  // namespace Luminary::Network

#endif  /* !LUMINARY_NETWORK_CONNECTION_HPP */
