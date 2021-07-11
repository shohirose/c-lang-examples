cmake_minimum_required(VERSION 3.14)
project(c-lang-examples-linalg C)

add_library(linalg
    matrix.c
    vector.c
    )
target_compile_features(linalg PUBLIC c_std_11)
target_compile_options(linalg
    PUBLIC
        $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    )
add_library(c-lang-examples::linalg ALIAS linalg)

add_executable(linalg-main main.c)
target_link_libraries(linalg-main
    PRIVATE
        c-lang-examples::linalg
    )