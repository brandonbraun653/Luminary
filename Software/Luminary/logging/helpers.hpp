/********************************************************************************
 *  File Name:
 *    helpers.hpp
 *
 *  Description:
 *    Common logging helpers
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_LOGGING_HELPERS_HPP
#define LUMINARY_LOGGING_HELPERS_HPP

/* uLog Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_vgdb_semihosting.hpp>
#include <uLog/sinks/sink_cout.hpp>

/*-------------------------------------------------------------------------------
Toggle Logging Categories
-------------------------------------------------------------------------------*/
static constexpr bool LOGGING_ENABLED = true;

static constexpr bool LOG_ERROR_ENABLED = true & LOGGING_ENABLED;
static constexpr bool LOG_INFO_ENABLED = true & LOGGING_ENABLED;
static constexpr bool LOG_DEBUG_ENABLED = true & LOGGING_ENABLED;


/*-------------------------------------------------------------------------------
Logging Helper Macros
-------------------------------------------------------------------------------*/
#define ERROR_MSG( logger, ... )                         \
  if constexpr ( LOG_ERROR_ENABLED )                     \
  {                                                      \
    logger->flog( uLog::Level::LVL_ERROR, __VA_ARGS__ ); \
  }

#define INFO_MSG( logger, ... )                         \
  if constexpr ( LOG_INFO_ENABLED )                     \
  {                                                     \
    logger->flog( uLog::Level::LVL_INFO, __VA_ARGS__ ); \
  }

#define DEBUG_MSG( logger, ... )                         \
  if constexpr ( LOG_DEBUG_ENABLED )                     \
  {                                                      \
    logger->flog( uLog::Level::LVL_DEBUG, __VA_ARGS__ ); \
  }


#endif  /* !LUMINARY_LOGGING_HELPERS_HPP */
