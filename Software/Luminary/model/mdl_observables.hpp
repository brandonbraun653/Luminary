/********************************************************************************
 *  File Name:
 *    mdl_observables.hpp
 *
 *  Description:
 *    Provides a simple interface for interacting with observable runtime data
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_MODEL_OBSERVABLES_HPP
#define LUMINARY_MODEL_OBSERVABLES_HPP

/* STL Includes */
#include <cstdint>
#include <cstddef>

/* Aurora Includes */
#include <Aurora/pattern>

/* Chimera Includes */
#include <Chimera/common>

namespace Luminary::Model
{
  enum class ObservableType : size_t
  {
    MASTER_LED_OUTPUT_STATE,  /**< Whether or not the main LED output (all channels) are ON/OFF */

    NUM_OPTIONS,
    INVALID
  };

  void initializeObservers();

  Chimera::Status_t pushEvent( const ObservableType type, Aurora::Structure::Observer::UpdateArgs *event );

  Chimera::Status_t registerObserver( const ObservableType type, Aurora::Structure::Observer::IObserver *observer );

  Chimera::Status_t removeObserver( const ObservableType type, Aurora::Structure::Observer::IObserver *observer );

}  // namespace Luminary::Model

#endif  /* !LUMINARY_MODEL_OBSERVABLES_HPP */
