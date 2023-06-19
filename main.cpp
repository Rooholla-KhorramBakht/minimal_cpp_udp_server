#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <thread>

struct imu_data_raw
{
  uint64_t accel_stamp;
  uint64_t gyro_stamp;
  int16_t accel[3];
  int16_t gyro[3];
  float temperature;
};

typedef struct imu_data_raw imu_data_raw_t;

union
{
  struct
  {
    uint8_t header[4];
    imu_data_raw_t data;
    uint64_t cam_sync_60hz_stamp;
    uint64_t cam_sync_30hz_stamp;
  } packet;
  char buffer[sizeof(imu_data_raw_t) + 4 + 8 + 8];
} udp_packet;

using boost::asio::ip::udp;

void start_server()
{
  try
  {
    boost::asio::io_service io_service;
    udp::socket socket(io_service, udp::endpoint(udp::v4(), 5555));

    for (;;)
    {
      boost::array<char, 128> recv_buf;
      udp::endpoint remote_endpoint;
      size_t len = socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);
      std::cout << len;
      memcpy(udp_packet.buffer, recv_buf.data(), sizeof(udp_packet.buffer));
      std::cout << "Accel: " << udp_packet.packet.data.accel[0] << ", " << udp_packet.packet.data.accel[1] << ", "
                << udp_packet.packet.data.accel[2] << std::endl;
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
