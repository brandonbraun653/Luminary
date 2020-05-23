/********************************************************************************
 *  File Name:
 *    rpc_main.cpp
 *
 *  Description:
 *    RPC driver for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>

/* Boost Includes */
#include <boost/circular_buffer.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/serial>
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/rpc/rpc_main.hpp>

namespace Luminary::RPC
{
  static Chimera::Serial::Serial_sPtr s_serial;

  static std::array<uint8_t, 50> s_rpc_hw_tx_buffer;
  static std::array<uint8_t, 50> s_rpc_hw_rx_buffer;

  static boost::circular_buffer<uint8_t> s_rpc_tx_circular_buffer( 50 );
  static boost::circular_buffer<uint8_t> s_rpc_rx_circular_buffer( 50 );

  void initializeModule()
  {
    s_serial = nullptr;
    s_rpc_hw_rx_buffer.fill( 0 );
    s_rpc_hw_tx_buffer.fill( 0 );
    s_rpc_rx_circular_buffer.clear();
    s_rpc_tx_circular_buffer.clear();
  }

  static Chimera::Status_t initializeSerial()
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
    s_serial    = create_shared_ptr( Channel::SERIAL1 );

    result |= s_serial->assignHW( Channel::SERIAL1, pins );
    result |= s_serial->configure( cfg );
    result |= s_serial->enableBuffering( SubPeripheral::TX, &s_rpc_tx_circular_buffer, s_rpc_hw_tx_buffer.data(), s_rpc_hw_tx_buffer.size() );
    result |= s_serial->enableBuffering( SubPeripheral::RX, &s_rpc_rx_circular_buffer, s_rpc_hw_rx_buffer.data(), s_rpc_hw_rx_buffer.size() );
    result |= s_serial->begin( PeripheralMode::INTERRUPT, PeripheralMode::INTERRUPT );

    return result;
  }

  void MainThread( void *argument )
  {
    
    if ( initializeSerial() != Chimera::CommonStatusCodes::OK ) 
    {
      Chimera::insert_debug_breakpoint();
    }

    
    std::string_view hello = "hello\r\n";

    while( true )
    {
      s_serial->write( reinterpret_cast<const uint8_t *>( hello.data() ), hello.size() );
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }

}  // namespace Luminary::Network
