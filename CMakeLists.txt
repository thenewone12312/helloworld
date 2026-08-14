cmake_minimum_required(VERSION 3.20)

project(HelloWorldGame LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HelloWorldGame
    src/glad.c
    src/main.cpp
    src/Input.cpp
    src/Object.cpp
    src/VAO.cpp
    src/VBO.cpp
    src/EBO.cpp
    src/Sprite.cpp
    src/Polygon.cpp
    src/Texture.cpp
    src/vector.cpp
    src/Physics.cpp
    src/stb.cpp
    src/shaders/Shader.cpp
    src/shaders/VertexShader.cpp
    src/shaders/FragmentShader.cpp
    src/shaders/ShaderProgram.cpp
    src/Player.cpp
    include/imgui/imgui.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_tables.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/backends/imgui_impl_glfw.cpp
    include/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(HelloWorldGame PRIVATE include include/imgui include/imgui/backends)

if(APPLE)
    target_link_directories(HelloWorldGame PRIVATE "${CMAKE_SOURCE_DIR}/lib-arm64")
    target_link_libraries(HelloWorldGame PRIVATE glfw3
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework Metal"
        "-framework QuartzCore")
elseif(WIN32)
    target_link_libraries(HelloWorldGame PRIVATE glfw3 opengl32 gdi32 user32 shell32 winmm)
else()
    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED)
    target_link_libraries(HelloWorldGame PRIVATE glfw OpenGL::GL)
endif()
