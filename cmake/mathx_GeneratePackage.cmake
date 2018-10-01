include(CMakePackageConfigHelpers)

# Get the include directories we need ...
get_directory_property(_INCLUDE_DIRS INCLUDE_DIRECTORIES)

set(MATHX_CONF_PREFIX ${CMAKE_INSTALL_PREFIX}/lib/libmathx.so)
set(CXX_FLAGS CMAKE_CXX_FLAGS)

configure_file(cmake/templates/mathx.pc.in
  "${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/mathx.pc"
  ESCAPE_QUOTES @ONLY)


install(
  FILES
    "${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/mathx.pc"
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig
  COMPONENT pkgconfig
)