cmake_minimum_required(VERSION 3.0.0)
project(streambase VERSION 0.1.0)

include_directories(common)
include_directories(server)
file(GLOB SERVER_SOURCES "common/*.cpp" "server/*.cpp")
add_executable(StreamBaseServer ${SERVER_SOURCES})

include_directories(client)
file(GLOB CLIENT_SOURCES "common/*.cpp" "client/*.cpp")
add_executable(StreamBaseClient ${CLIENT_SOURCES})
