CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(biginteger)

OPTION(TEST "Build all tests." OFF) # Makes boolean 'test' available.

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 5.0)
      set(CPP_STD_VERSION "--std=c++14")
    elseif (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.7)
      set(CPP_STD_VERSION "--std=c++11")
    elseif (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.6)
      set(CPP_STD_VERSION "--std=c++0x")
    else()
      message(FATAL_ERROR "gcc version must be at least 4.6!")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 3.2)
      set(CPP_STD_VERSION "--std=c++11")
    else()
      message(FATAL_ERROR "Clang version must be at least 3.2!")
    endif()
else()
    message(WARNING "You are using an unsupported compiler: \"" ${CMAKE_CXX_COMPILER_ID})
endif()


if (CMAKE_VERSION VERSION_LESS 3.0) # for travis ...
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_STD_VERSION}")
else()
    ADD_COMPILE_OPTIONS(${CPP_STD_VERSION})
endif()

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/libbiginteger/)

IF(TEST)
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/libbiginteger/)
  ADD_SUBDIRECTORY(test)
ENDIF()

