/********************************************************************************
 *  File Name:
 *    rpc_action_brightness.cpp
 *
 *  Description:
 *    Defines the action for setting brightness levels
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>

/* Luminary Includes */
#include <Luminary/model/mdl_observables.hpp>
#include <Luminary/rpc/rpc_responder.hpp>
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  size_t actionSetBrightnessRelative( MessageBuffer &message, const CommandID cmd )
  {
    return 0;
  }

  size_t actionSetBrightnessAbsolute( MessageBuffer &message, const CommandID cmd )
  {
    return 0;
  }

}  // namespace Luminary::RPC
