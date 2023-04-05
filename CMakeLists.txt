cmake_minimum_required(VERSION 3.0)

# Executable name
set(PROJECT_NAME tetris)

project(${PROJECT_NAME} CXX)

# Source files
file(GLOB SOURCES "src/*.cpp")

#SFML lib location
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)

include_directories(${SFML_DIR}/include)

link_directories(${SFML_DIR}/lib)

add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

add_compile_options(ofast -o3 optimizations on steroids)