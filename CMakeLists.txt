cmake_minimum_required(VERSION 2.8)

# Executable name
set(PROJECT_NAME
    tetris
)

project(${PROJECT_NAME} CXX)

#Source files
set( SRC
	src/main.cpp
)

#SFML lib location
set( CMAKE_SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/../SFML-2.5.1
)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
