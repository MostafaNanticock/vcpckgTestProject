cmake_minimum_required(VERSION 3.15)
project(ExPac VERSION 1.0.0 LANGUAGES CXX)

# Option to build as shared (default: OFF - static)
option(BUILD_SHARED_LIBS "Build libraries as shared instead of static" ON)

# Enable exporting targets
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set a default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Core)
add_subdirectory(Manager)

# Packaging support
include(CMakePackageConfigHelpers)

# Install the package configuration files
install(EXPORT ExPacTargets
    FILE ExPacTargets.cmake
    NAMESPACE ExPac::
    DESTINATION lib/cmake/ExPac
)

write_basic_package_version_file(
    ${CMAKE_BINARY_DIR}/ExPacConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_file(ExPacConfig.cmake.in ${CMAKE_BINARY_DIR}/ExPacConfig.cmake @ONLY)

install(FILES
    ${CMAKE_BINARY_DIR}/ExPacConfig.cmake
    ${CMAKE_BINARY_DIR}/ExPacConfigVersion.cmake
    DESTINATION lib/cmake/ExPac
)
