###############################################################
cmake_minimum_required(VERSION 3.4)
project(run_test VERSION 1.0 LANGUAGES CXX C)

configure_file(include/config.h.in config.h)
include_directories(${PROJECT_BINARY_DIR})

###############################################################
# require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

###############################################################
# Setup debug build
if(CMAKE_BUILD_TYPE MATCHES Debug)
  message(STATUS "Configuring debug build.")
  set(CMAKE_DEBUG_POSTFIX d)
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall -Wextra -Wpedantic -Werror") # <- Beware of -Werror when using this line
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall")
  add_compile_definitions(DEBUG)
endif()

find_package(Boost 1.80 REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

###############################################################
# extra compile-time flags in code
# add_compile_definitions(VERBOSE)
# add_compile_definitions(NON_PERIODIC_BOUNDARY_CONDITIONS)


###############################################################
# include useful compiler/linker flags
if (CMAKE_BUILD_TYPE MATCHES Release )
  message(STATUS "Configuring release build.")
  set(GCC_COVERAGE_COMPILE_FLAGS "-Ofast -s -march=native -mtune=native")
endif()
set(GCC_COVERAGE_LINK_FLAGS    "-lstdc++")
set(CMAKE_CXX_FLAGS         "-g")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

message(CMAKE_CXX_FLAGS="${CMAKE_CXX_FLAGS}")


###############################################################
# set the default build type to Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

###############################################################
# add include directories
include_directories(include)

add_executable(${PROJECT_NAME} "")

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE src)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR})

###############################################################
# Generate helper script to clean cmake
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/clean-cmake.sh
  COMMAND echo '#!/bin/bash
  rm -r CMakeCache.txt  CMakeFiles Makefile  ccake cmake_install.cmake  config.h src' > ${CMAKE_CURRENT_BINARY_DIR}/clean-cmake.sh
)
