/********************************************************************************
 *  File Name:
 *    rpc_action_output_state.cpp
 *
 *  Description:
 *    Defines the action for setting the output state
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
  size_t actionSetOutputState( MessageBuffer &message, const CommandID cmd )
  {
    using namespace Luminary::Model;
    using namespace Aurora::Structure::Observer;

    auto result               = Chimera::CommonStatusCodes::FAIL;
    constexpr auto observable = ObservableType::MASTER_LED_OUTPUT_STATE;

    /*------------------------------------------------
    Figure out which state the output needs to be in
    ------------------------------------------------*/
    bool outputState = false;

    UpdateArgs args;
    args.data = &outputState;
    args.size = sizeof( outputState );

    switch ( cmd )
    {
      case CMD_ID_TURN_OUTPUT_ON:
        outputState = true;
        break;

      case CMD_ID_TURN_OUTPUT_OFF:
        outputState = false;
        break;

      default:
        return invalidHandlerResponse( message );
        break;
    }

    /*------------------------------------------------
    Push the event to all observers
    ------------------------------------------------*/
    if ( pushEvent( observable, &args ) == Chimera::CommonStatusCodes::OK )
    {
      return ackResponse( message, cmd );
    }
    else
    {
      return nackResponse( message, cmd );
    }
  }
}  // namespace Luminary::RPC
