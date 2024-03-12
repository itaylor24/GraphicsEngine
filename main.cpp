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
#include "Model.h"
#include "LightSource.h"


int width = 800;
int height = 800;

Camera camera(width, height);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        std::cout << "Key pressed: " << key << std::endl;
    }
    switch (key) {
        case 83:
            std::cout << "S" << std::endl;
            camera.zoomOut();
            break;
        case 87:
            std::cout << "W" << std::endl;
            camera.zoomIn();
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


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "GraphicsEngine", nullptr, nullptr);
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

    Model* model = new Model("../models/xyzrgb_dragon.obj");
    LightSource* light = new LightSource();
    Renderer renderer;

    float lightPosition[] = {0.f, 30.0f, 0.f};
    float amb[] = {.2f, 0.f, .3f, .1};


    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");

    model->attachCamera(&camera);
    model->setLightSource(light);
    model->setDiffuse(amb);

    light->attachCamera(&camera);
    light->controlPosition(lightPosition);

    renderer.AddItem(model);
    renderer.AddItem(light);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        renderer.Clear();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        renderer.Draw();

        //ImGUI
        {
            ImGui::Begin("ColorSelect");
            ImGui::ColorEdit4("Color", amb);

            ImGui::SliderFloat("LightPosX", &lightPosition[0], -120, 120);
            ImGui::SliderFloat("LightPosY", &lightPosition[1], -120, 120);
            ImGui::SliderFloat("LightPosZ", &lightPosition[2], -120, 120);

            ImGui::End();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (!ImGui::GetIO().WantCaptureMouse && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            camera.mouseUpdate(glm::vec2 (xpos, ypos));
        }

    }

    glfwTerminate();
    return 0;
}
