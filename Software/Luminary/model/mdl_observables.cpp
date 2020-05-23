/********************************************************************************
 *  File Name:
 *    mdl_observables.cpp
 *
 *  Description:
 *    Implements the observable runtime interface
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>

/* Aurora Includes */
#include <Aurora/pattern>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/model/mdl_observables.hpp>

namespace Luminary::Model
{
  using namespace Aurora::Structure::Observer;
  using namespace Chimera::Threading;

  static std::array<Observable, static_cast<size_t>( ObservableType::NUM_OPTIONS )> s_observable_objects;


  /*-------------------------------------------------
  Master LED Output
  -------------------------------------------------*/
  namespace MLO
  {
    static std::array<IObserver *, 3> registrationList;
    static ControlBlock controlBlock = { .elements = registrationList.size(), .list = registrationList.data(), .inUse = false };
  }    // namespace MLO

  void initializeObservers()
  {
    auto type = static_cast<size_t>( ObservableType::INVALID );

    /*-------------------------------------------------
    Master LED Output
    -------------------------------------------------*/
    type = static_cast<size_t>( ObservableType::MASTER_LED_OUTPUT_STATE );
    s_observable_objects[ type ].registerControlBlock( &MLO::controlBlock, TIMEOUT_DONT_WAIT );
    s_observable_objects[ type ].setType( type );
  }


  Chimera::Status_t pushEvent( const ObservableType type, Aurora::Structure::Observer::UpdateArgs *event )
  {
    if ( type < ObservableType::NUM_OPTIONS )
    {
      return s_observable_objects[ static_cast<size_t>( type ) ].update( event, TIMEOUT_BLOCK );
    }
    else
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }
  }


  Chimera::Status_t registerObserver( const ObservableType type, Aurora::Structure::Observer::IObserver *observer )
  {
    if ( type < ObservableType::NUM_OPTIONS )
    {
      return s_observable_objects[ static_cast<size_t>( type ) ].attach( observer, TIMEOUT_BLOCK );
    }
    else
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }
  }


  Chimera::Status_t removeObserver( const ObservableType type, Aurora::Structure::Observer::IObserver *observer )
  {
    if ( type < ObservableType::NUM_OPTIONS )
    {
      return s_observable_objects[ static_cast<size_t>( type ) ].detach( observer, TIMEOUT_BLOCK );
    }
    else
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }
  }

}    // namespace Luminary::Model
