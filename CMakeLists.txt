cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(HelloWorld)

    find_package(fmt CONFIG REQUIRED)


add_executable(HelloWorld helloworld.cpp)

    target_link_libraries(HelloWorld PRIVATE fmt::fmt)