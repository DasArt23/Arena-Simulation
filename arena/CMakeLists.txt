cmake_minimum_required(VERSION 3.28)
project(ArenaSimulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(ARENA_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")

set(SFML_STATIC_LIBRARIES ON)

find_package(
    SFML 3 
    CONFIG
    REQUIRED 
    COMPONENTS Graphics
)

add_custom_target(run
    COMMAND $<TARGET_FILE:ArenaSimulation>
    DEPENDS ArenaSimulation
	COMMENT "Running Arena Simulation..."
)


if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(compile_commands
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_BINARY_DIR}/compile_commands.json"
            "${ARENA_ROOT}/compile_commands.json"
        COMMENT "Copying compile_commands.json to source directory..."
    )
	if(TARGET run)
		add_dependencies(run compile_commands)
	endif()
endif()

add_executable(ArenaSimulation 
    ${ARENA_ROOT}/main.cpp
    ${ARENA_ROOT}/src/app/app.cpp
    ${ARENA_ROOT}/src/window/window.cpp
	${ARENA_ROOT}/src/window/render.cpp
	${ARENA_ROOT}/src/window/shape.cpp
	${ARENA_ROOT}/src/math/clock.cpp
)


target_link_libraries(ArenaSimulation PRIVATE SFML::Graphics)
target_include_directories(ArenaSimulation PRIVATE ${ARENA_ROOT}/src)
