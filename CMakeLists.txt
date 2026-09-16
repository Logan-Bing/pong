cmake_minimum_required(VERSION 3.20)
project(pong CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Genere compile_commands.json pour clangd (nvim)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

set(SRCS_DIR srcs)
set(INC_DIR includes)
set(UTILS_DIR utils)

add_executable(${PROJECT_NAME} 
	${SRCS_DIR}/main.cpp 
	${SRCS_DIR}/Game.cpp
	${SRCS_DIR}/Render.cpp
	${SRCS_DIR}/Simulation.cpp
	${SRCS_DIR}/ViewPort.cpp
	${SRCS_DIR}/InSimulationState.cpp
	${SRCS_DIR}/MenuState.cpp
	${SRCS_DIR}/PauseState.cpp
	${SRCS_DIR}/ServiceState.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR} ${UTILS_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wconversion)

add_executable(tests EXCLUDE_FROM_ALL
	${SRCS_DIR}/test.cpp
	${SRCS_DIR}/Simulation.cpp
	${SRCS_DIR}/Game.cpp
)
target_include_directories(tests PRIVATE ${INC_DIR} ${UTILS_DIR})
target_compile_options(tests PRIVATE -Wall -g -fsanitize=address)
target_link_options(tests PRIVATE -fsanitize=address)

# Symlink de compile_commands.json a la racine du projet
add_custom_target(copy_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
