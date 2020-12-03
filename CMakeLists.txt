cmake_minimum_required(VERSION 3.0.0)
project(game-of-life VERSION 0.1.0)


include(CTest)
enable_testing()

include_directories(/usr/local/cuda/include)

find_package( Threads )

find_package(CUDA REQUIRED)

set(CMAKE_CXX_STANDARD 17)
add_executable(game-of-life simple.cu)

enable_language(CUDA)

add_compile_options(--extended-lambda)
target_link_libraries( game-of-life ${CMAKE_THREAD_LIBS_INIT} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
