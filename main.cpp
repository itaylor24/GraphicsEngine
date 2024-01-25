#include <iostream>
#include <fstream>
#include <cassert>

#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "Renderer.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"


int main() {

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "OpenGL", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    if(glewInit() != GLEW_OK)
       std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    float positions[] =
        {
            -0.5f, -0.5f,
            1.0f, 0.f, 0.f,
            0.5f, -0.5f,
            1.0f, 1.f, 0.f,
            0.5f, 0.5f,
            1.0f, 0.f, 1.f,
        };

    unsigned int indices [] = {
        0, 1, 2,
    };

    VertexArray VAO;
    VertexBuffer VBO(positions, sizeof(positions));
    VertexBufferLayout layout;

    layout.Push<float>(2);
    layout.Push<float>( 3);

    VAO.AddBuffer(VBO, layout);
    VAO.Bind();

    IndexBuffer IBO(indices, std::size(indices));

    Shader shader("../shaders/Basic.vert", "../shaders/Basic.frag");


    float redChannel = 0.0f;
    float inc = .01f;

    VAO.Unbind();
    shader.Unbind();
    IBO.Unbind();
    VBO.Unbind();

    Renderer renderer;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        renderer.Clear();

        redChannel += inc;
        inc = (redChannel >= 1.0f || redChannel <= 0.0f) ? -inc : inc;

        shader.Bind();
        shader.SetUniform4f("u_Color", redChannel, .2f, .7f, 1.0f);

        renderer.Draw(VAO, IBO, shader);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
