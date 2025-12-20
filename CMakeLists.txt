cmake_minimum_required(VERSION 3.27)
project(CompetitiveProgramming)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

add_executable(sandbox _Sandbox/main.cpp)
target_compile_definitions(sandbox PRIVATE LOCAL_RUN)
