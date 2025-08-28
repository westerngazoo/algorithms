# Find all files in the current directory ending with .cpp
file(GLOB EXAMPLE_SOURCES "*.cpp")

# Loop through each source file that was found.
foreach(EXAMPLE_SOURCE IN LISTS EXAMPLE_SOURCES)
    # Get the filename without the .cpp extension.
    # For "example_usage.cpp", EXAMPLE_NAME becomes "example_usage".
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)

    # Create a new executable with that name.
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})

    # Link our 'goose' library to the new executable.
    target_link_libraries(${EXAMPLE_NAME} PRIVATE Goose::goose)
endforeach()