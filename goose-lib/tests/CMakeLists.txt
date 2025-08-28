# Download and configure Google Test.
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG    v1.14.0 # Corrected tag format
)
FetchContent_MakeAvailable(googletest)

# --- Create Test Executable ---
# Find all test source files automatically.
file(GLOB TEST_SOURCES "*.cpp")
add_executable(run_tests ${TEST_SOURCES})

# Link our 'goose' library and Google Test to the test executable.
target_link_libraries(run_tests PRIVATE Goose::goose gtest_main)

# --- Register Tests with CTest ---
include(GoogleTest)
gtest_discover_tests(run_tests)