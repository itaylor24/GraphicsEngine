#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

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

    //allocate memory
    ShapeData* info = (ShapeData*)malloc(sizeof (ShapeData));
    unsigned int* indexBuffer = (unsigned int*) malloc(5000000000*sizeof (unsigned int));
    Vertex* vertexBuffer = (Vertex* ) malloc(5000000000*sizeof (Vertex));

    info->indices = indexBuffer;
    info->vertices = vertexBuffer;

    //parse data
    Mesh::Parse("../models/pumpkin.obj", info);

    //setup MVP matrix
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -15.5f));
    glm::mat4 rotation2 = glm::rotate(glm::mat4(1.0f), glm::radians(40.f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width) / (float)height, 0.1f, 10000.0f);
    glm::mat4 MVP = projectionMatrix * camera.getWorldToViewMatrix() * translation * rotation;



    //setup opengl objects
    VertexArray VAOCar;
    VertexBuffer VBOCar(info->vertices, info->vertexBufferSize());
    IndexBuffer IBOCar(indexBuffer , info->indexBufferSize());

    VertexBufferLayout layoutCar;
    layoutCar.Push<float>(3);
    layoutCar.Push<float>(3);
    layoutCar.Push<float>(3);

    VAOCar.AddBuffer(VBOCar, layoutCar);
    VAOCar.Bind();

    Shader shader("../shaders/Basic.vert", "../shaders/Basic.frag");

    Renderer renderer;

    float lightPosition[] = {0.f, 200.0f, 0.f};
    float amb[] = {.2f, 0.f, .3f, .1};
    glm::vec3 matColor(1.f);

    shader.Bind();

    shader.SetUniform3f("u_Color", matColor);


    shader.Unbind();
    VAOCar.Unbind();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        renderer.Clear();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();



        MVP = projectionMatrix * camera.getWorldToViewMatrix() * translation * rotation * camera.getRotation();

        shader.Bind();
        shader.SetUniformMatrix4fv("MVP", MVP);
        shader.SetUniform3f("ambientLight", glm::vec4 (amb[0], amb[1], amb[2], amb[3]));
        shader.SetUniform3f("lightPosition", glm::vec3 (lightPosition[0], lightPosition[1], lightPosition[2]));

        renderer.Draw(VAOCar, IBOCar, shader);

        ImGui::Begin("ColorSelect");
        ImGui::ColorEdit4("Color", amb);

        ImGui::SliderFloat("LightPosX", &lightPosition[0], -500, 500);
        ImGui::SliderFloat("LightPosY", &lightPosition[1], -500, 500);
        ImGui::SliderFloat("LightPosZ", &lightPosition[2], -500, 500);

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        ;

        if (!ImGui::GetIO().WantCaptureMouse && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            camera.mouseUpdate(glm::vec2 (xpos, ypos));
        }

    }


    free(info);
    free(vertexBuffer);
    free(indexBuffer);

    glfwTerminate();
    return 0;
}
