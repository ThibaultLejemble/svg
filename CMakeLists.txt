project(svg)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS                "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG          "-g3 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE        "-DNDEBUG -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3")

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE FILE_H   src/*.h  )
file(GLOB_RECURSE FILE_HPP src/*.hpp)
file(GLOB_RECURSE FILE_CPP src/*.cpp)
file(GLOB_RECURSE FILE_INL src/*.inl)
set(SOURCES ${FILE_H} ${FILE_HPP} ${FILE_CPP} ${FILE_INL})

include_directories(src/)

add_executable(example1 examples/example1.cpp ${SOURCES})
