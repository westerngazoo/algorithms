# Minimum CMake version required (VERY IMPORTANT for C++ modules).
cmake_minimum_required(VERSION 3.28)

# Project definition.
project(Goose VERSION 1.0 LANGUAGES CXX)

# --- C++ Standard Configuration ---
# Use C++23 which is widely available; modules need at least C++20 features.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ensure we have a generator that supports C++ modules (Ninja / Ninja Multi-Config / VS 17.4+).
if(NOT (CMAKE_GENERATOR MATCHES "Ninja" OR (MSVC AND CMAKE_GENERATOR MATCHES "Visual Studio")))
    message(STATUS "Generator '${CMAKE_GENERATOR}' may not support C++20 modules. Consider: cmake -G Ninja -B build")
endif()

# Let CMake scan for module dependencies automatically.
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# --- Library Creation ---
# Create the library, initially empty.
add_library(goose STATIC)
add_library(Goose::goose ALIAS goose) # Add a namespaced alias for modern CMake usage

# --- Add Sources and Modules ---
# Use target_sources() to let CMake scan module dependencies.
target_sources(goose PUBLIC
    FILE_SET public_modules # Lowercase to satisfy CMake naming rules
    TYPE CXX_MODULES       # Explicitly define the type
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
    FILES
        # List all your module interfaces here
        include/goose/algorithm/factorial.cppm
        include/goose/algorithm/sort.cppm
)

# --- Include Directories ---
# The 'include' directory is public so that consumers of the library
# can find the module files.
target_include_directories(goose PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# --- Testing ---
enable_testing()
add_subdirectory(tests)

# --- Examples ---
add_subdirectory(examples)

# --- Benchmarks ---
option(GOOSE_BUILD_BENCHMARKS "Build benchmark suite" ON)
if(GOOSE_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

# --- Installation ---
# Defines where the files will be installed on the system.
include(GNUInstallDirs)
install(TARGETS goose
    EXPORT goose-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    FILE_SET public_modules DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Generate the CMake configuration file so other projects
# can find and use this library with `find_package(Goose)`.
install(EXPORT goose-targets
    FILE GooseTargets.cmake
    NAMESPACE Goose::
    DESTINATION lib/cmake/Goose
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "cmake/GooseConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/GooseConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/Goose"
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/GooseConfig.cmake"
    DESTINATION "lib/cmake/Goose"
)