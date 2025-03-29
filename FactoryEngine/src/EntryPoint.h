#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

#include "Core.h"
#include "Mesh.h"
#include "EngineConfig.h"
#include "MeshRenderer.h"
#include "Utilities.h"
#include "RenderAPI.h"


using namespace Factory;
using namespace Utilities;
using namespace FactoryEngine;
using namespace RenderAPI;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main(int argc, char* argv[]) {
	std::cout << "Factory Engine." << std::endl;

	EngineConfig config =  GetEngineConfig("resources/engineconfig.ini");
	RenderingAPI::Initialize(config.renderAPIName.c_str());

	Window* window = RenderingAPI::CreateWindow(SCR_WIDTH, SCR_HEIGHT, "Factory Engine");

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

	while (!window->ShouldClose()) {
		window->ProcessInput();

		window->ClearColor(0.5, 0.8, 0.9, 1.0);

		shaderProgram->Activate();
		meshRenderer.Render();

		window->SwapBuffers();
		window->PollEvents();
	}

	delete shaderProgram;
	delete window;

	RenderingAPI::Terminate();

	return 0;
}
