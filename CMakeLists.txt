cmake_minimum_required(VERSION 3.16)
project(ArenaSimulation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML REQUIRED COMPONENTS system window graphics)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(copy_compile_commands
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_BINARY_DIR}/compile_commands.json"
            "${CMAKE_SOURCE_DIR}/compile_commands.json"
        COMMENT "Copying compile_commands.json to source directory..."
    )
	if(TARGET run)
		add_dependencies(run compile_commands)
	endif()
endif()

add_executable(ArenaSimulation 
    main.cpp
    src/app/app.cpp
    src/window/window.cpp
	src/window/render.cpp
	src/window/shape.cpp
	src/math/clock.cpp
)

add_custom_target(run
    COMMAND $<TARGET_FILE:ArenaSimulation>
    DEPENDS ArenaSimulation
	COMMENT "Running Arena Simulation..."
)

target_link_libraries(ArenaSimulation PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(ArenaSimulation PRIVATE src)
