cmake_minimum_required(VERSION 2.8.11)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 URL                 https://github.com/google/googletest/archive/release-1.7.0.tar.gz
                 URL_HASH            SHA1=d7aa4b8536f3a007b480cf016be8a4333dbf4768
                 LOG_DOWNLOAD        1
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
INCLUDE_DIRECTORIES(${googletest_SOURCE_DIR}/include/)

# Trivial example using gtest and gmock
FILE(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

SET(TEST_EXECUTABLE ${PROJECT_NAME}_test)
add_executable(${TEST_EXECUTABLE} ${TEST_SOURCES})
target_link_libraries(${TEST_EXECUTABLE} gtest biginteger)
ADD_CUSTOM_COMMAND(TARGET ${TEST_EXECUTABLE}
                   POST_BUILD
                   COMMENT "Running unit tests..."
                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_test)
