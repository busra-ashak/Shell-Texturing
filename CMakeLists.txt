project(ShellTexturing)

cmake_minimum_required(VERSION 3.29 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_executable(shell
  src/main.cpp
  src/buffer.cpp
  src/shader.cpp
)

add_subdirectory(lib)

target_link_libraries(shell PRIVATE glfw glad glm)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_options(shell PRIVATE -g -O0)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    target_compile_options(shell PRIVATE -O3)
endif()
