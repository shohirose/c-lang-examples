cmake_minimum_required(VERSION 3.14)
project(c-lang-examples)

add_library(linalg
    src/matrix.c
    src/vector.c
    )
target_compile_features(linalg PUBLIC c_std_11)
target_compile_options(linalg
    PUBLIC
        $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
        $<$<C_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    )
target_include_directories(linalg
PUBLIC
    include
)

add_executable(test src/test.c)
target_link_libraries(test
    PRIVATE
        linalg
    )