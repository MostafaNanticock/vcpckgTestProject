# Define a custom option to control whether Core is built as shared or static
option(LIB_CORE_BUILD_SHARED "Build the Core library as a shared library" ${BUILD_SHARED_LIBS})

# Determine the library type based on the LIB_CORE_BUILD_SHARED option
set(CORE_LIB_TYPE STATIC) # Default to static
if(LIB_CORE_BUILD_SHARED)
    set(CORE_LIB_TYPE SHARED)
endif()

set(HEADERS
    Core.hpp
)

set(SOURCES
    Core.cpp
)

# Define the Core library
add_library(Core
    ${CORE_LIB_TYPE}
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(Core
    PRIVATE

)

# Specify public include directories
target_include_directories(Core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/Core>
)

# Install the header file (move it to include/Core during installation)
install(FILES
    ${HEADERS} DESTINATION include/Core
)

# Install the library
install(TARGETS Core EXPORT ExPacTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
