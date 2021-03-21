#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "qhttpengine" for configuration "Release"
set_property(TARGET qhttpengine APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(qhttpengine PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/qhttpengine.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/qhttpengine.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS qhttpengine )
list(APPEND _IMPORT_CHECK_FILES_FOR_qhttpengine "${_IMPORT_PREFIX}/lib/qhttpengine.lib" "${_IMPORT_PREFIX}/bin/qhttpengine.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
