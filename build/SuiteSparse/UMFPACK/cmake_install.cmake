# Install script for directory: C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Coding/VS/suitesparse/build/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/Debug/libumfpackd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/Release/libumfpack.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/MinSizeRel/libumfpack.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/RelWithDebInfo/libumfpack.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/Debug/libumfpackd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/Release/libumfpack.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/MinSizeRel/libumfpack.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/RelWithDebInfo/libumfpack.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/suitesparse" TYPE FILE FILES
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_col_to_triplet.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_defaults.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_free_numeric.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_free_symbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_get_determinant.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_get_lunz.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_get_numeric.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_get_symbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_global.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_load_numeric.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_load_symbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_numeric.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_qsymbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_control.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_info.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_matrix.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_numeric.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_perm.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_status.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_symbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_triplet.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_report_vector.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_save_numeric.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_save_symbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_scale.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_solve.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_symbolic.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_tictoc.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_timer.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_transpose.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_triplet_to_col.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/UMFPACK/Include/umfpack_wsolve.h"
    )
endif()

