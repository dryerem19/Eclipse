cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 20)

find_program(CMAKE_MAKE_PROGRAM ninja)
if(CMAKE_MAKE_PROGRAM)
  set(CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM}" CACHE PATH "Path to ninja build tool")
else()
  message(FATAL_ERROR "Ninja build tool not found")
endif()

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project(Eclipse)

add_subdirectory(eclipse)
add_subdirectory(examples)