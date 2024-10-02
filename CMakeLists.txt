cmake_minimum_required(VERSION 3.10)

project(http)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(include)

add_executable(${PROJECT_NAME} "main.cpp")


