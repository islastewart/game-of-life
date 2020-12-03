cmake_minimum_required(VERSION 3.0.0)
project(game-of-life VERSION 0.1.0)


include(CTest)
enable_testing()

find_package( Threads )


set(CMAKE_CXX_STANDARD 17)
add_executable(game-of-life main.cpp)

target_link_libraries( game-of-life ${CMAKE_THREAD_LIBS_INIT} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
