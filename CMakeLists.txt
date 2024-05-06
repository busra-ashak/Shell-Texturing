project(ShellTexturing)

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_executable(shell
  main.cpp
)

target_compile_options(shell PRIVATE -g -O3)
