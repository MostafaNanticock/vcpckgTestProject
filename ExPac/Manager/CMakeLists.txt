set(SOURCES
    Manager.cpp
)

set(HEADERS
    Manager.hpp
)

# Define the Manager library
add_library(Manager
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(Manager
    PRIVATE
    Core
)

# Specify public include directories
target_include_directories(Manager PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/Manager>
)

# Install the header file (move it to include/Manager during installation)
install(FILES
    ${HEADERS} DESTINATION include/Manager
)

# Install the library
install(TARGETS Manager
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
