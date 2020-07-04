/********************************************************************************
 *  File Name:
 *    serial.cpp
 *
 *  Description:
 *    Implements the Luminary interface for the Serial driver
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>
#include <cstring>

/* Boost Includes */
#include <boost/circular_buffer.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/serial>

/* Luminary Includes */
#include <Luminary/hardware/hwm_serial.hpp>

namespace Luminary::Hardware::Serial
{
  /*-------------------------------------------------------------------------------
  Configuration Variables
  -------------------------------------------------------------------------------*/
  // Length of the hardware buffer for transceiving a Serial message
  static constexpr size_t HWBufferSize = 128;

  // Length of the user buffer for queueing multiple messages
  static constexpr size_t CircularBufferSize = 2 * HWBufferSize;

  // Serial Transmit Buffers
  static std::array<uint8_t, HWBufferSize> sTXHWBuffer;
  static boost::circular_buffer<uint8_t> sTXCircularBuffer( CircularBufferSize );

  // Serial Recieve Buffers
  static std::array<uint8_t, HWBufferSize> sRXHWBuffer;
  static boost::circular_buffer<uint8_t> sRXCircularBuffer( CircularBufferSize );

  Chimera::Status_t configureDriver()
  {
    using namespace Chimera::Serial;
    using namespace Chimera::Hardware;

    /*------------------------------------------------
    Configuration info for the serial object
    ------------------------------------------------*/
    IOPins pins;
    pins.tx.alternate = Chimera::GPIO::Alternate::USART1_TX;
    pins.tx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    pins.tx.pin       = 9;
    pins.tx.port      = Chimera::GPIO::Port::PORTA;
    pins.tx.pull      = Chimera::GPIO::Pull::NO_PULL;
    pins.tx.threaded  = true;
    pins.tx.validity  = true;

    pins.rx.alternate = Chimera::GPIO::Alternate::USART1_RX;
    pins.rx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    pins.rx.pin       = 10;
    pins.rx.port      = Chimera::GPIO::Port::PORTA;
    pins.rx.pull      = Chimera::GPIO::Pull::NO_PULL;
    pins.rx.threaded  = true;
    pins.rx.validity  = true;


    Config cfg;
    cfg.baud     = 115200;
    cfg.flow     = FlowControl::FCTRL_NONE;
    cfg.parity   = Parity::PAR_NONE;
    cfg.stopBits = StopBits::SBITS_ONE;
    cfg.width    = CharWid::CW_8BIT;

    /*------------------------------------------------
    Create the serial object and initialize it
    ------------------------------------------------*/
    auto result = Chimera::CommonStatusCodes::OK;
    auto Serial = create_shared_ptr( HWChannel );

    if ( !Serial )
    {
      Chimera::insert_debug_breakpoint();
    }

    result |= Serial->assignHW( HWChannel, pins );
    result |= Serial->configure( cfg );
    result |= Serial->enableBuffering( SubPeripheral::TX, &sTXCircularBuffer, sTXHWBuffer.data(),
                                         sTXHWBuffer.size() );
    result |= Serial->enableBuffering( SubPeripheral::RX, &sRXCircularBuffer, sRXHWBuffer.data(),
                                         sRXHWBuffer.size() );
    result |= Serial->begin( PeripheralMode::INTERRUPT, PeripheralMode::INTERRUPT );

    return result;

  }
}  // namespace Luminary::Hardware::Serial
