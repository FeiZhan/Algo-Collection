cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(acm)
file(GLOB SOURCE_FILES main.cpp include/dbg-1.20/dbg.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include_directories(include include/dbg-1.20)
target_link_libraries(${PROJECT_NAME})
