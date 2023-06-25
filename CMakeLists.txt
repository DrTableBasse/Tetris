cmake_minimum_required(VERSION 3.0)

# Executable name
set(PROJECT_NAME tetris)

project(${PROJECT_NAME} CXX)

# Source files
file(GLOB SOURCES "src/*.cpp" 
"libs/ImGui/*.cpp"
)

#SFML lib location
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/ImGui)

include_directories(${SFML_DIR}/include
${IMGUI_DIR}
)

link_directories(${SFML_DIR}/lib
${IMGUI_DIR}
)


add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        opengl32
)
add_compile_options(
        ofast   #-o3 optimizations on steroids
)
