project(svg)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS                "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG          "-g3 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE        "-DNDEBUG -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3")

set(CMAKE_CXX_STANDARD 17)

option(SVG_EXAMPLES "Compile exmaples" OFF)

file(GLOB_RECURSE FILE_H   src/*.h  )
file(GLOB_RECURSE FILE_HPP src/*.hpp)
file(GLOB_RECURSE FILE_CPP src/*.cpp)
file(GLOB_RECURSE FILE_INL src/*.inl)
set(SOURCES ${FILE_H} ${FILE_HPP} ${FILE_CPP} ${FILE_INL})

add_library(svg ${SOURCES})
target_include_directories(svg PUBLIC src)

if(${SVG_EXAMPLES})
    add_executable(example1_hello_word examples/example1_hello_word.cpp)
    target_link_libraries(example1_hello_word PRIVATE svg)

    add_executable(example2_basic_shapes examples/example2_basic_shapes.cpp)
    target_link_libraries(example2_basic_shapes PRIVATE svg)

    add_executable(example3_group examples/example3_group.cpp)
    target_link_libraries(example3_group PRIVATE svg)

    add_executable(example4_style examples/example4_style.cpp)
    target_link_libraries(example4_style PRIVATE svg)

    add_executable(example5_use_symbol examples/example5_use_symbol.cpp)
    target_link_libraries(example5_use_symbol PRIVATE svg)

    add_executable(example6_image examples/example6_image.cpp)
    target_link_libraries(example6_image PRIVATE svg)
endif()
