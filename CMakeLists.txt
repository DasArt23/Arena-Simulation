cmake_minimum_required(VERSION 3.28)

project(ArenaSimulationSuperbuild NONE)

include(ExternalProject)

set(DEPS_INSTALL_DIR "${CMAKE_BINARY_DIR}/dependencies")

ExternalProject_Add(
    SFML_external

    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW TRUE

    INSTALL_DIR "${DEPS_INSTALL_DIR}/sfml"

    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DBUILD_SHARED_LIBS:BOOL=OFF

        -DSFML_BUILD_AUDIO:BOOL=OFF
        -DSFML_BUILD_NETWORK:BOOL=OFF

        -DSFML_BUILD_EXAMPLES:BOOL=OFF
        -DSFML_BUILD_DOC:BOOL=OFF
)

ExternalProject_Add(
    ArenaSimulation_external

    SOURCE_DIR "${CMAKE_SOURCE_DIR}/arena"

    CMAKE_ARGS
        -DCMAKE_PREFIX_PATH:PATH=${DEPS_INSTALL_DIR}/sfml
        -DSFML_STATIC_LIBRARIES:BOOL=ON

    BUILD_ALWAYS TRUE

    INSTALL_COMMAND ""

    DEPENDS SFML_external
)
