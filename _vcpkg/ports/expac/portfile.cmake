# # Ensure the source directory exists
# vcpkg_extract_source_archive_ex(
#     OUT_SOURCE_PATH SOURCE_PATH
#     ARCHIVE ${CMAKE_CURRENT_LIST_DIR}
# )

# Configure the project
vcpkg_cmake_configure(
    SOURCE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../ExPac
#    PREFER_NINJA # Optional: Use Ninja if available
    OPTIONS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} # Use the current CMake build type
        -DCMAKE_INSTALL_PREFIX=${CURRENT_PACKAGES_DIR} # Install to the correct location
)

# Build the project
vcpkg_cmake_build(
    TARGET install
)
