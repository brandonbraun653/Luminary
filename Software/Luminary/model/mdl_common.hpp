/********************************************************************************
 *  File Name:
 *    mdl_common.hpp
 *
 *  Description:
 *    Interface for accesing common data in Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_MODEL_COMMON_HPP
#define LUMINARY_MODEL_COMMON_HPP

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/common>

namespace Luminary::Model
{

  enum class CommonData : uint8_t
  {
    DBG_LED_STATUS_BLINK_PERIOD,   /**< Period at which the debug status LED should blink (ms) */

    NUM_DATA_FIELDS,
    INVALID
  };

  /**
   *  Initializes the memory associated with the model module
   *  @return Chimera::Status_t
   */
  Chimera::Status_t initializeModule();

  /**
   *  Updates the common data field in a thread & memory safe manner
   *
   *  @param[in]  field       Which data parameter to update
   *  @param[in]  data        Address of the data to copy
   *  @param[in]  size        Size of the data in bytes
   *  @param[in]  timeout     How long to wait for access to the data
   *
   *  @return Chimera::Status_t
   */
  Chimera::Status_t setDataSafe( const CommonData field, void *const data, const size_t size, const size_t timeout );

  /**
   *  Grabs the common data field in a thread & memory safe manner
   *
   *  @param[in]  field       Which data parameter to retrieve
   *  @param[out] data        Address of the data to copy into
   *  @param[in]  size        Size of the data in bytes
   *  @param[in]  timeout     How long to wait for access to the data
   *
   *  @return Chimera::Status_t
   */
  Chimera::Status_t getDataSafe( const CommonData field, void *const data, const size_t size, const size_t timeout );

}  // namespace Luminary::Model

#endif  /* !LUMINARY_MODEL_COMMON_HPP */
