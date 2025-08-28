set_property(TARGET "Goose::goose"
  PROPERTY IMPORTED_CXX_MODULES_NOCONFIG
    "goose.algorithm:factorial=${_IMPORT_PREFIX}/include/goose/algorithm/factorial.cppm"
    "goose.algorithm=${_IMPORT_PREFIX}/include/goose/algorithm/sort.cppm"
)
