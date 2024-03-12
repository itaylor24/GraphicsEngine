cmake_minimum_required(VERSION 3.26)
project(GraphicsEngine)

set(CMAKE_CXX_STANDARD 17)

set(IMGUI_SRC
        imgui/imgui_impl_opengl3.h
        imgui/imgui_impl_opengl3.cpp
        imgui/imgui_impl_opengl3_loader.h
        imgui/imgui_impl_glfw.h
        imgui/imgui_impl_glfw.cpp
        imgui/imgui.h
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_demo.cpp
        MeshLayout.h
        Model.cpp
        Model.h
        RenderingItem.cpp
        RenderingItem.h
        LightSource.cpp
        LightSource.h
        Scene.cpp
        Scene.h
)


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
        Mesh.h
        ${IMGUI_SRC}
        )

add_subdirectory(glfw)

target_link_libraries(GraphicsEngine glfw)

add_subdirectory(glm)
target_link_libraries(GraphicsEngine glm)

find_package(OpenGL REQUIRED)
target_link_libraries(GraphicsEngine OpenGL::GL)

find_package(GLEW 2.0 REQUIRED)
target_link_libraries(GraphicsEngine GLEW::GLEW)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address ")