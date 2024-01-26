#include <iostream>
#include <fstream>
#include <cassert>

#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Renderer.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Types.h"
#include "Shapes.h"

int main() {

    GLFWwindow* window;


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );

    int width = 800;
    int height = 800;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "OpenGL", nullptr, nullptr);
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


    glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), 54.0f, glm::vec3(-1.0f, -1.0f, 0.0f));
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width) / (float)height, 0.1f, 10.0f);

    glm::mat4 MVP = projectionMatrix * translation * rotation;

    ShapeData cube = Shapes::makeCube();
    ShapeData triangle = Shapes::makeTriangle();

    VertexArray VAO;
    VertexBuffer VBO(cube.vertices, cube.vertexBufferSize());
    //VertexBuffer VBO(triangle.vertices, triangle.vertexBufferSize());
    VertexBufferLayout layout;

    layout.Push<float>(3);
    layout.Push<float>(3);

    VAO.AddBuffer(VBO, layout);
    VAO.Bind();

    IndexBuffer IBO(cube.indices, cube.indexBufferSize());
    //IndexBuffer IBO(triangle.indices, triangle.indexBufferSize());

    std::cout << cube.vertexBufferSize() << std::endl;
    std::cout << cube.indexBufferSize() << std::endl;


    Shader shader("../shaders/Basic.vert", "../shaders/Basic.frag");

    shader.Bind();
    shader.SetUniformMatrix4fv("MVP", MVP);

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

//        redChannel += inc;
//        inc = (redChannel >= 1.0f || redChannel <= 0.0f) ? -inc : inc;

        shader.Bind();
//        shader.SetUniform4f("u_Color", redChannel, .2f, .7f, 1.0f);

        renderer.Draw(VAO, IBO, shader);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }



    glfwTerminate();
    return 0;
}
