cmake_minimum_required(VERSION 3.20)
project(pong CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Genere compile_commands.json pour clangd (nvim)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} 
	main.cpp 
	Game.cpp
	Render.cpp
	Simulation.cpp
	ViewPort.cpp
	Timer.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wconversion)

# Symlink de compile_commands.json a la racine du projet
add_custom_target(copy_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
