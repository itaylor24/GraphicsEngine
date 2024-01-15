cmake_minimum_required(VERSION 3.26)
project(GraphicsEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphicsEngine main.cpp)



add_subdirectory(glfw)

target_link_libraries(GraphicsEngine glfw)


find_package(OpenGL REQUIRED)
target_link_libraries(GraphicsEngine OpenGL::GL)

find_package(GLEW 2.0 REQUIRED)
target_link_libraries(GraphicsEngine GLEW::GLEW)