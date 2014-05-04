cmake_minimum_required(VERSION 2.8)

PROJECT(SUMO)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g++")
endif(CMAKE_COMPILER_IS_GNUCXX)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
	message(ERROR "OpenGL not found")
endif(NOT OPENGL_FOUND)

set(SUMO_SRCS.cpp
	Main.cpp
	Game.cpp
	Camera.cpp
	CubeObject.cpp
	LevelCube.cpp
	BoundingBox.cpp
	Player.cpp
	GameObject.cpp
)
set(SUMO_HDRS.h
	Game.h
	Camera.h
	CubeObject.h
	LevelCube.h
	BoundingBox.h
	Player.h
	Gameobject.h
)
add_executable(sumo $(SUMO_SRCS) $(SUMO_HDRS))
target_link_libraries(sumo ${sdl_PREFIX}/lib/libSDL2.a pthread dl)