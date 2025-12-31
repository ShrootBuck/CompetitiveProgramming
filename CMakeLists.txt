cmake_minimum_required(VERSION 4.2.0)
project(CompetitiveProgramming)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(WARNING_FLAGS -Wall -Wextra -Wshadow -Wfloat-equal)

set(SANITIZE_FLAGS -fsanitize=address,undefined -fno-omit-frame-pointer)

add_compile_definitions(ZK_LOCAL_RUN _LIBCPP_DEBUG=1)

add_compile_options(
        -O0
        ${WARNING_FLAGS}
        ${SANITIZE_FLAGS}
)

add_link_options(
        ${SANITIZE_FLAGS}
        -Wl,-stack_size,0x10000000  # Sets stack to 256MB (Mac specific)
)

add_executable(sandbox _Sandbox/main.cpp)
target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR})
