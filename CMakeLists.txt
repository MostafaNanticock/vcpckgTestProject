cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(HelloWorld)

find_package(fmt CONFIG REQUIRED)
find_package(crashpad CONFIG REQUIRED)

add_definitions(-DBOOST_DLL_USE_STD_FS)

add_executable(HelloWorld helloworld.cpp)
target_link_libraries(HelloWorld PRIVATE fmt::fmt crashpad::crashpad)
target_include_directories(HelloWorld PRIVATE ${Boost_INCLUDE_DIRS})
