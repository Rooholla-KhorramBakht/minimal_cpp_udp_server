cmake_minimum_required(VERSION 3.10)

project(UDPServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.65.1 REQUIRED COMPONENTS system thread)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(UDPServer main.cpp)
  target_link_libraries(UDPServer ${Boost_LIBRARIES} -pthread)
endif()
