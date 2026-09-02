cmake_minimum_required(VERSION 3.10.0)
project(radicent)

include_directories(
    vndr/glad/include
    vndr/glfw/include
    vndr/imgui
    vndr/imgui/backends
)

add_subdirectory(./vndr/glfw glfw)

add_executable(radicent 
    vndr/glad/src/glad.c

    vndr/imgui/imgui.cpp
    vndr/imgui/imgui_demo.cpp
    vndr/imgui/imgui_draw.cpp
    vndr/imgui/imgui_tables.cpp
    vndr/imgui/imgui_widgets.cpp

    vndr/imgui/backends/imgui_impl_glfw.cpp
    vndr/imgui/backends/imgui_impl_opengl3.cpp

    src/main.cpp
    src/io.cpp
    src/log.cpp
)

target_link_libraries(radicent glfw)

