cmake_minimum_required(VERSION 3.18)

project(HelloWorld CXX)

add_executable(main main.cpp)

find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE ZLIB::ZLIB fmt::fmt)

find_program(VCPKG_EXECUTABLE NAMES vcpkg PATHS ENV VCPKG_ROOT)
message(STATUS "vcpkg executable path: ${VCPKG_EXECUTABLE}")
message(STATUS "Using vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "VCPKG_MANIFEST_DIR: ${VCPKG_MANIFEST_DIR}")
message(STATUS "Z_VCPKG_ROOT_DIR: ${Z_VCPKG_ROOT_DIR}")
message(STATUS "_VCPKG_INSTALLED_DIR: ${_VCPKG_INSTALLED_DIR}")
message(STATUS "VCPKG_ROOT: $ENV{VCPKG_ROOT}")

execute_process(
    COMMAND "${Z_VCPKG_EXECUTABLE}" export
    --zip
    --output-dir=.
    --output=vcpkg_prebuilt
    --triplet "${VCPKG_TARGET_TRIPLET}"
    --vcpkg-root "${Z_VCPKG_ROOT_DIR}"
    "--x-wait-for-lock"
    "--x-manifest-root=${VCPKG_MANIFEST_DIR}"
    "--x-install-root=${_VCPKG_INSTALLED_DIR}"
    ${Z_VCPKG_FEATURE_FLAGS}
    ${Z_VCPKG_ADDITIONAL_MANIFEST_PARAMS}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    RESULT_VARIABLE VCPKG_EXPORT_RESULT
)
message(STATUS "vcpkg export result: ${VCPKG_EXPORT_RESULT}")
