cmake_minimum_required(VERSION 3.10)
project(vmm_simulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(include)

set(SRC
    src/main.cpp
    src/FIFOManager.cpp
    src/LRUManager.cpp
    src/OptimalManager.cpp
)

add_executable(vmm_simulator ${SRC})
