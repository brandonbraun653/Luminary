/********************************************************************************
 *  File Name:
 *    rpc_action_animation.cpp
 *
 *  Description:
 *    Defines the action for setting animations
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
  size_t actionSetAnimationGlobal( MessageBuffer &message, const CommandID cmd )
  {
    return 0;
  }

  size_t actionSetAnimationDevice( MessageBuffer &message, const CommandID cmd )
  {
    return 0;
  }

}  // namespace Luminary::RPC
