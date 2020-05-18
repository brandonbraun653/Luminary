/********************************************************************************
 *  File Name:
 *    mdl_common.cpp
 *
 *  Description:
 *    Common data used in Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstdlib>
#include <cstring>

/* Chimera Includes */
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/model/mdl_common.hpp>

namespace Luminary::Model
{
  static Chimera::Threading::RecursiveTimedMutex sGlobalLock;

  /*-------------------------------------------------
  Parameter data
  -------------------------------------------------*/
  static size_t s_dbg_led_blink_period;

  Chimera::Status_t initializeModule()
  {
    s_dbg_led_blink_period = 500;

    return Chimera::CommonStatusCodes::OK;
  }

  Chimera::Status_t setDataSafe( const CommonData field, void *const data, const size_t size, const size_t timeout )
  {
    /*-------------------------------------------------
    Input parameter protection
    -------------------------------------------------*/
    if ( !data || !size )
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }

    /*-------------------------------------------------
    Try and get global access to the data
    -------------------------------------------------*/
    if( !sGlobalLock.try_lock_for( timeout ) )
    {
      return Chimera::CommonStatusCodes::LOCKED;
    }

    /*-------------------------------------------------
    Copy out the information
    -------------------------------------------------*/
    switch( field )
    {
      case CommonData::DBG_LED_STATUS_BLINK_PERIOD:
          if( size != sizeof( s_dbg_led_blink_period ) )
          {
            return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
          }

          memcpy( &s_dbg_led_blink_period, data, sizeof(s_dbg_led_blink_period ) );
        break;

      case CommonData::INVALID:
      default:
        return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
        break;
    }

    return Chimera::CommonStatusCodes::OK;
  }

  Chimera::Status_t getDataSafe( const CommonData field, void *const data, const size_t size, const size_t timeout )
  {
    /*-------------------------------------------------
    Input parameter protection
    -------------------------------------------------*/
    if ( !data || !size )
    {
      return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
    }

    /*-------------------------------------------------
    Try and get global access to the data
    -------------------------------------------------*/
    if( !sGlobalLock.try_lock_for( timeout ) )
    {
      return Chimera::CommonStatusCodes::LOCKED;
    }

    /*-------------------------------------------------
    Copy out the information
    -------------------------------------------------*/
    switch( field )
    {
      case CommonData::DBG_LED_STATUS_BLINK_PERIOD:
          if( size != sizeof( s_dbg_led_blink_period ) )
          {
            return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
          }

          memcpy( data, &s_dbg_led_blink_period, sizeof(s_dbg_led_blink_period ) );
        break;

      case CommonData::INVALID:
      default:
        return Chimera::CommonStatusCodes::INVAL_FUNC_PARAM;
        break;
    }

    return Chimera::CommonStatusCodes::OK;
  }

}  // namespace Luminary::Model
