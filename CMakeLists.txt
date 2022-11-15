#Minimum version of CMake that can run this script
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(asteroids VERSION 1.0)

# Find SDL package
find_package(SDL2 REQUIRED)

# Request c++11 standard features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Export compile commands for code completion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set up configuration header file
#configure_file(include/Config.h.in
#	"${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h")

# Compile the passed source files into an executable
add_executable(asteroids
	"${CMAKE_CURRENT_SOURCE_DIR}/src/asteroid.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/asteroid.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/bullet.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/bullet.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/entity.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/entity.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/input.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/input.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/player.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/player.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/render.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/render.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/vec2.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/vec2.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/world.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/world.cpp"
	)

# Reference include directory
target_include_directories(asteroids PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${SDL_INCLUDE_DIRS}"
	)

target_link_libraries(asteroids ${SDL2_LIBRARIES})

# Set the output directory for executables
set_target_properties(asteroids
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
