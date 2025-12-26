cmake_minimum_required(VERSION 3.27)
project(CompetitiveProgramming)

# Generate compile_commands.json for clangd/VSCode so you get proper intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

# These are lists. CMake loves lists.
set(WARNING_FLAGS -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal)
set(SANITIZE_FLAGS -fsanitize=address,undefined -fno-omit-frame-pointer)

add_compile_definitions(LOCAL_RUN _LIBCPP_DEBUG=1)

# Don't manually edit CMAKE_CXX_FLAGS.
# add_compile_options applies these to all targets (executables) in this project.
add_compile_options(
    -g
    -O0
    ${WARNING_FLAGS}
    ${SANITIZE_FLAGS}
)

add_link_options(${SANITIZE_FLAGS})

add_executable(sandbox _Sandbox/main.cpp)
