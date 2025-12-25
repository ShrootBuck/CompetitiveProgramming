cmake_minimum_required(VERSION 3.27)
project(CompetitiveProgramming)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

set(WARNING_FLAGS -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal)

set(SANITIZE_FLAGS -fsanitize=address,undefined -fno-omit-frame-pointer)

add_compile_definitions(LOCAL_RUN _LIBCPP_DEBUG=1)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 ${WARNING_FLAGS} ${SANITIZE_FLAGS}")

add_executable(sandbox _Sandbox/main.cpp)
