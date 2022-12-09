cmake_minimum_required(VERSION 2.8)
project(tetris)
set( SRC
	src/main.cpp
	src/example.cpp
)
add_executable(tetris ${SRC})
target_link_libraries(tetris GL GLU GLEW glfw)