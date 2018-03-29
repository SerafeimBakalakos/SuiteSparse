#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SuiteSparse::suitesparseconfig" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::suitesparseconfig APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::suitesparseconfig PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "C"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/suitesparseconfig.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::suitesparseconfig )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::suitesparseconfig "${_IMPORT_PREFIX}/lib/suitesparseconfig.lib" )

# Import target "SuiteSparse::amd" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::amd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::amd PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libamd.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libamd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::amd )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::amd "${_IMPORT_PREFIX}/lib/libamd.lib" "${_IMPORT_PREFIX}/bin/libamd.dll" )

# Import target "SuiteSparse::btf" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::btf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::btf PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libbtf.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libbtf.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::btf )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::btf "${_IMPORT_PREFIX}/lib/libbtf.lib" "${_IMPORT_PREFIX}/bin/libbtf.dll" )

# Import target "SuiteSparse::camd" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::camd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::camd PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcamd.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libcamd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::camd )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::camd "${_IMPORT_PREFIX}/lib/libcamd.lib" "${_IMPORT_PREFIX}/bin/libcamd.dll" )

# Import target "SuiteSparse::ccolamd" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::ccolamd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::ccolamd PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libccolamd.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libccolamd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::ccolamd )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::ccolamd "${_IMPORT_PREFIX}/lib/libccolamd.lib" "${_IMPORT_PREFIX}/bin/libccolamd.dll" )

# Import target "SuiteSparse::colamd" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::colamd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::colamd PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcolamd.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libcolamd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::colamd )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::colamd "${_IMPORT_PREFIX}/lib/libcolamd.lib" "${_IMPORT_PREFIX}/bin/libcolamd.dll" )

# Import target "SuiteSparse::cholmod" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::cholmod APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::cholmod PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcholmod.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libcholmod.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::cholmod )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::cholmod "${_IMPORT_PREFIX}/lib/libcholmod.lib" "${_IMPORT_PREFIX}/bin/libcholmod.dll" )

# Import target "SuiteSparse::cxsparse" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::cxsparse APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::cxsparse PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcxsparse.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libcxsparse.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::cxsparse )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::cxsparse "${_IMPORT_PREFIX}/lib/libcxsparse.lib" "${_IMPORT_PREFIX}/bin/libcxsparse.dll" )

# Import target "SuiteSparse::klu" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::klu APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::klu PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libklu.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libklu.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::klu )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::klu "${_IMPORT_PREFIX}/lib/libklu.lib" "${_IMPORT_PREFIX}/bin/libklu.dll" )

# Import target "SuiteSparse::ldl" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::ldl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::ldl PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libldl.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libldl.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::ldl )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::ldl "${_IMPORT_PREFIX}/lib/libldl.lib" "${_IMPORT_PREFIX}/bin/libldl.dll" )

# Import target "SuiteSparse::umfpack" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::umfpack APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::umfpack PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libumfpack.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libumfpack.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::umfpack )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::umfpack "${_IMPORT_PREFIX}/lib/libumfpack.lib" "${_IMPORT_PREFIX}/bin/libumfpack.dll" )

# Import target "SuiteSparse::spqr" for configuration "RelWithDebInfo"
set_property(TARGET SuiteSparse::spqr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SuiteSparse::spqr PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libspqr.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libspqr.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SuiteSparse::spqr )
list(APPEND _IMPORT_CHECK_FILES_FOR_SuiteSparse::spqr "${_IMPORT_PREFIX}/lib/libspqr.lib" "${_IMPORT_PREFIX}/bin/libspqr.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
