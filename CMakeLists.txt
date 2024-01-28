cmake_minimum_required(VERSION 3.26)
project(GraphicsEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphicsEngine main.cpp
        Renderer.h
        Renderer.cpp
        VertexBuffer.h
        VertexBuffer.cpp
        IndexBuffer.cpp
        IndexBuffer.h
        VertexBufferLayout.h
        VertexArray.cpp
        VertexArray.h
        Shader.cpp
        Shader.h
        Types.h
        Shapes.cpp
        Shapes.h
        Camera.cpp
        Camera.h
        utils.h
        utils.cpp
        Mesh.cpp
        Mesh.h)



add_subdirectory(glfw)

target_link_libraries(GraphicsEngine glfw)

add_subdirectory(glm)
target_link_libraries(GraphicsEngine glm)

find_package(OpenGL REQUIRED)
target_link_libraries(GraphicsEngine OpenGL::GL)

find_package(GLEW 2.0 REQUIRED)
target_link_libraries(GraphicsEngine GLEW::GLEW)