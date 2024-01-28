#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "utils.h"
#include "Renderer.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Types.h"
#include "Shapes.h"
#include "Camera.h"

#include "Mesh.h"

Camera camera;


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        std::cout << "Key pressed: " << key << std::endl;
    }
    switch (key) {
        case 68:
            std::cout << "D" << std::endl;
            camera.moveRight();
            break;
        case 65:
            std::cout << "A" << std::endl;
            camera.moveLeft();
            break;
        case 83:
            std::cout << "S" << std::endl;
            camera.moveBackward();
            break;
        case 87:
            std::cout << "W" << std::endl;
            camera.moveForward();
        case 84:
            std::cout << "T" << std::endl;
            camera.moveUp();
            break;
        case 82:
            std::cout << "R" << std::endl;
            camera.moveDown();
            break;
        default:
            // Handle other keys if needed
            break;
    }
}

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

    glfwSetKeyCallback(window, keyCallback);

    if(glewInit() != GLEW_OK)
       std::cout << "Error!" << std::endl;


    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    ShapeData* info = (ShapeData*)malloc(sizeof (ShapeData));
    unsigned int* indexBuffer = (unsigned int*) malloc(50000000*sizeof (unsigned int));
    Vertex* vertexBuffer = (Vertex* ) malloc(50000000*sizeof (Vertex));
    info->indices = indexBuffer;
    info->vertices = vertexBuffer;

    Mesh::Parse("../pumpkin.obj", info);
    std::cout << info->numIndices << "WOOOW" << std::endl;


    //memcpy(indexBuffer, info->indices, 500000*sizeof (unsigned int));

    for (int i = 0; i < info->numIndices; ++i) {
        std::cout << info->indices[i];
    }
    //Car.showVertices();

    //ShapeData* carData = Car.data;


    glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -50.5f));
    glm::mat4 translation2 = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 1.0f, -100.0f));
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), 1.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotation2 = glm::rotate(glm::mat4(1.0f), 1.0f, glm::vec3(-1.0f, -1.0f, 0.0f));
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width) / (float)height, 0.1f, 500.0f);

    glm::mat4 MVP = projectionMatrix * camera.getWorldToViewMatrix() * translation * rotation;

    ShapeData cube = Shapes::makeCube();
    ShapeData triangle = Shapes::makeTriangle();
    ShapeData plane = Shapes::makePlane();

    VertexArray VAOcube;
    VertexArray VAOplane;
    VertexArray VAOCar;

    VertexBuffer VBOcube(cube.vertices, cube.vertexBufferSize());
    VertexBuffer VBOplane(plane.vertices, plane.vertexBufferSize());
    VertexBuffer VBOCar(info->vertices, info->vertexBufferSize());

    std::cout << info->vertexBufferSize() << std::endl;
    std::cout << sizeof (Vertex) << std::endl;

    VertexBuffer VBO(triangle.vertices, triangle.vertexBufferSize());
    VertexBufferLayout layoutCube;


    layoutCube.Push<float>(3);
    layoutCube.Push<float>(3);

    VAOcube.AddBuffer(VBOcube, layoutCube);
    VAOcube.Bind();

    IndexBuffer IBOcube(cube.indices, cube.indexBufferSize());

    VertexBufferLayout layoutPlane;
    layoutPlane.Push<float>(3);
    layoutPlane.Push<float>(3);

    VAOplane.AddBuffer(VBOplane, layoutPlane);
    VAOplane.Bind();

    IndexBuffer IBOplane(plane.indices, plane.indexBufferSize());

    VertexBufferLayout layoutCar;
    layoutCar.Push<float>(3);
    layoutCar.Push<float>(3);

    VAOCar.AddBuffer(VBOCar, layoutCar);
    VAOCar.Bind();

    std::cout << info->indexBufferSize();

    IndexBuffer IBOCar(indexBuffer , info->indexBufferSize());


    IndexBuffer IBO(triangle.indices, triangle.indexBufferSize());

    std::cout << cube.vertexBufferSize() << std::endl;
    std::cout << cube.indexBufferSize() << std::endl;


    Shader shader("../shaders/Basic.vert", "../shaders/Basic.frag");

    shader.Bind();
    shader.SetUniformMatrix4fv("MVP", MVP);

    float redChannel = 0.0f;
    float inc = .01f;



    VAOplane.Unbind();
    shader.Unbind();
    IBOplane.Unbind();
    VBOplane.Unbind();

    Renderer renderer;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        renderer.Clear();

//        redChannel += inc;
//        inc = (redChannel >= 1.0f || redChannel <= 0.0f) ? -inc : inc;

        shader.Bind();
        MVP = projectionMatrix * camera.getWorldToViewMatrix() * translation * rotation;
        shader.SetUniformMatrix4fv("MVP", MVP);

//        shader.SetUniform4f("u_Color", redChannel, .2f, .7f, 1.0f);

        //renderer.Draw(VAOcube, IBOcube, shader);

        //MVP = projectionMatrix * camera.getWorldToViewMatrix() * translation2 * rotation2;
        shader.SetUniformMatrix4fv("MVP", MVP);

        //renderer.Draw(VAOplane, IBOplane, shader);
        renderer.Draw(VAOCar, IBOCar, shader);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            camera.mouseUpdate(glm::vec2 (xpos, ypos));
        }

    }



    glfwTerminate();
    return 0;
}
