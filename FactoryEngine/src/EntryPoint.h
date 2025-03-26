#pragma once

#include <string>
#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "MeshRenderer.h"
#include "RenderAPI.h"
#include "Utilities.h"


using namespace Factory;
using namespace Utilities;
using namespace FactoryEngine;
using namespace RenderAPI;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    std::cout << "Factory Engine." << std::endl;

    if (glfwInit() == GLFW_FALSE) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Factory Engine", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	ShaderProgram* shaderProgram = RenderingAPI::CreateShaderProgram();


    std::string vertexShaderSource = ReadFile("resources/shaders/vertex.glsl");
    std::string fragmentShaderSource = ReadFile("resources/shaders/fragment.glsl");

	shaderProgram->AddSource(vertexShaderSource, ShaderType::VERTEX_SHADER);
	shaderProgram->AddSource(fragmentShaderSource, ShaderType::FRAGMENT_SHADER);
	shaderProgram->Compile();


    std::vector<Vertex> vertices = {
        Vertex(0.5f,  0.5f, 0.0f),
        Vertex(0.5f, -0.5f, 0.0f),
        Vertex(-0.5f, -0.5f, 0.0f),
        Vertex(-0.5f,  0.5f, 0.0f)
    };
    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3
    };

    Mesh mesh(vertices, indices);
    MeshRenderer meshRenderer(&mesh);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.5, 0.8, 0.9, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram->Activate();
        meshRenderer.Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete shaderProgram;

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}