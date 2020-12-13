cmake_minimum_required(VERSION 3.17)
project(c8lang)

set(CMAKE_CC_FLAGS "-Wall -Wfatal-errors")
set(CMAKE_CC_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)

# Preprocess re files to generate lexer
add_custom_command(OUTPUT lexer.c
    COMMAND re2c -W --no-version --no-generation-date -i
    -o "${CMAKE_CURRENT_BINARY_DIR}/lexer.c" "${CMAKE_SOURCE_DIR}/src/lexer.re"
    DEPENDS src/lexer.re
)

add_executable(c8lang
    src/main.c
    src/token.c
    lexer.c
)
target_include_directories(c8lang PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
)

# TODO: integrate cheat tests into cmake
add_executable(test_c8lang
    test/tests.c
    src/token.c
    lexer.c
)
target_include_directories(test_c8lang PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/test"
)