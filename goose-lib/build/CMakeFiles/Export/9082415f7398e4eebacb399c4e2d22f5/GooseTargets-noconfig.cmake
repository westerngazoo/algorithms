#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Goose::goose" for configuration ""
set_property(TARGET Goose::goose APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Goose::goose PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libgoose.a"
  )

list(APPEND _cmake_import_check_targets Goose::goose )
list(APPEND _cmake_import_check_files_for_Goose::goose "${_IMPORT_PREFIX}/lib/libgoose.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
