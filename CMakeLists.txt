cmake_minimum_required(VERSION 3.21.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/library")

# add src files
set(MAIN_SRC_FILES src/main.cpp src/BigInteger.cpp)
set(BM_SRC_FILES graph/Benchmark.cpp src/BigInteger.cpp)

# for the shared library
set(BIGINT_SRC_FILES src/BigInteger.cpp)
set(BIGINT_HEADER_FILES include/BigInteger.hpp)

# add header files
include_directories(
   "./include"
)

if (UNIX)
  string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror -Wno-format-security -Wno-self-assign-overloaded")
endif()

add_executable(main ${MAIN_SRC_FILES})
add_executable(benchmark ${BM_SRC_FILES})

# create library
add_library(BigInteger SHARED ${BIGINT_SRC_FILES})

set_target_properties(BigInteger PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
)
