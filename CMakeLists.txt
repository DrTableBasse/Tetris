cmake_minimum_required(VERSION 3.0)

# Executable name
set(PROJECT_NAME tetris)

project(${PROJECT_NAME} CXX)

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ImGui)

if (CMAKE_HOST_SYSTEM MATCHES Windows)
        # Source files
        file(GLOB SOURCES "src/*.cpp" 
        "libs/ImGui/*.cpp"
        )

        set(CMAKE_CURRENT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dos-libs)
  
        #Lib location
        set(SFML_DIR ${CMAKE_CURRENT_LIB_DIR}/SFML-2.5.1)

        include_directories(${SFML_DIR}/include
        ${IMGUI_DIR}
        )

        link_directories(${SFML_DIR}/lib)


        add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

        target_link_libraries(${PROJECT_NAME}
                sfml-graphics
                sfml-window
                sfml-system
                sfml-audio
                opengl32
        )
endif()

if (CMAKE_HOST_SYSTEM MATCHES Linux)

       # Source files
       file(GLOB SOURCES "src/*.cpp" 
       "unix-libs/ImGui/*.cpp"
       )

       set(CMAKE_CURRENT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/unix-libs)
 
       #Libs location
       set(SFML_DIR ${CMAKE_CURRENT_LIB_DIR}/SFML-2.5.1)

       include_directories(
                ${SFML_DIR}/include
                ${IMGUI_DIR}
       )

       link_directories(${SFML_DIR}/lib)


       add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

        # OpenGL
        find_package(OpenGL REQUIRED)
        find_package(GLUT REQUIRED)

        target_link_libraries(
                ${PROJECT_NAME}
                ImGui-SFML
                sfml-graphics
                sfml-window
                sfml-system
                sfml-audio
                openal FLAC
                GLU GL X11 Xrandr udev pthread
        )
endif()