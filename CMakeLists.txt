cmake_minimum_required(VERSION 3.0.0)
project(game-of-life VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_USE_PTHREADS_INIT 1)
add_executable(game-of-life main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
