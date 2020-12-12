cmake_minimum_required(VERSION 3.17)
project(c8lang)

set(CMAKE_CC_STANDARD 99)

set(CMAKE_BUILD_TYPE Debug)

include_directories(
    "${CMAKE_SOURCE_DIR}/src"
)

# Preprocess re files to generate lexer
add_custom_command(OUTPUT lexer.cpp
    COMMAND re2c -W --no-version --no-generation-date -i
    -o ${CMAKE_CURRENT_BINARY_DIR}/lexer.c src/lexer.re
    DEPENDS src/lexer.re
)

add_executable(c8lang
    src/main.c
    src/token.c
)