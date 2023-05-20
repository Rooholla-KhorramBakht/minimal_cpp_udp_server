#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::udp;

void start_server()
{
  try
  {
    boost::asio::io_service io_service;
    udp::socket socket(io_service, udp::endpoint(udp::v4(), 8080));

    for (;;)
    {
      boost::array<char, 128> recv_buf;
      udp::endpoint remote_endpoint;
      size_t len = socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);

      std::string message(recv_buf.data(), len);
      std::istringstream sstream(message);
      float f1, f2, f3;
      char ch;  // For the comma

      sstream >> f1 >> ch >> f2 >> ch >> f3;

      std::cout << "Received numbers: " << f1 << ", " << f2 << ", " << f3 << std::endl;
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

int main()
{
  std::thread server_thread(start_server);

  // TODO: Do your stuff here

  server_thread.join();  // Wait for the server thread to finish

  return 0;
}
