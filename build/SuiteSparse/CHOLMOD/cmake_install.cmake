# Install script for directory: C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/Debug/libcholmodd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/Release/libcholmod.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/MinSizeRel/libcholmod.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Coding/VS/suitesparse/build/lib/RelWithDebInfo/libcholmod.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/Debug/libcholmodd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/Release/libcholmod.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/MinSizeRel/libcholmod.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Coding/VS/suitesparse/build/lib/RelWithDebInfo/libcholmod.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/suitesparse" TYPE FILE FILES
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_blas.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_camd.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_check.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_cholesky.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_complexity.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_config.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_core.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_function.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_gpu.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_gpu_kernels.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_internal.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_io64.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_matrixops.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_modify.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_partition.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_supernodal.h"
    "C:/Coding/VS/suitesparse/SuiteSparse/CHOLMOD/Include/cholmod_template.h"
    )
endif()

