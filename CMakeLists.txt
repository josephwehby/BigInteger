cmake_minimum_required(VERSION 3.21.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)

set(EXECUTABLE_OUTPUT_PATH "bin")

# add src files
set(MAIN_SRC_FILES src/main.cpp src/BigInteger.cpp)
set(BM_SRC_FILES src/Benchmark.cpp src/BigInteger.cpp)

#add header files
include_directories(
   "./include"
)

if (UNIX)
  string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror -Wno-format-security -Wno-self-assign-overloaded")
endif()

add_executable(main ${MAIN_SRC_FILES})
add_executable(benchmark ${BM_SRC_FILES})
