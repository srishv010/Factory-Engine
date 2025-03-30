#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

#include "Core.h"
#include "Mesh.h"
#include "Camera.h"
#include "EngineConfig.h"
#include "MeshRenderer.h"
#include "Utilities.h"
#include "RenderAPI.h"
#include "GameObject.h"


using namespace Factory;
using namespace Utilities;
using namespace FactoryEngine;
using namespace RenderAPI;

const unsigned int SCR_WIDTH = 960;
const unsigned int SCR_HEIGHT = 540;


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


	int width, height, colorChannels;
	unsigned char* data = ReadImage("resources/textures/proto.png", &width, &height, &colorChannels);
	Texture* texture = RenderingAPI::CreateTexture(data, width, height, colorChannels);



	std::vector<Vertex> vertices = {
		              // Positions                   // Texture coordinates
		// Front face
		Vertex(       -0.5f, -0.5f, 0.5f,            0.0f,  1.0f),
		Vertex(       0.5f, -0.5f, 0.5f,             1.0f,  1.0f),
		Vertex(       0.5f,  0.5f, 0.5f,             1.0f,  0.0f),
		Vertex(       -0.5f,  0.5f, 0.5f,            0.0f,  0.0f),

		// Back face				          
		Vertex(       -0.5f, -0.5f, -0.5f,           0.0f,  0.0f),
		Vertex(       -0.5f,  0.5f, -0.5f,           0.0f,  1.0f),
		Vertex(       0.5f,  0.5f, -0.5f,            1.0f,  1.0f),
		Vertex(       0.5f, -0.5f, -0.5f,            1.0f,  0.0f),

		// Left face				          
		Vertex(       -0.5f, -0.5f, -0.5f,           0.0f,  0.0f),
		Vertex(       -0.5f, -0.5f,  0.5f,           0.0f,  1.0f),
		Vertex(       -0.5f,  0.5f,  0.5f,           1.0f,  1.0f),
		Vertex(       -0.5f,  0.5f, -0.5f,           1.0f,  0.0f),

		// Right face				          
		Vertex(       0.5f, -0.5f, -0.5f,            0.0f,  0.0f),
		Vertex(       0.5f,  0.5f, -0.5f,            0.0f,  1.0f),
		Vertex(       0.5f,  0.5f,  0.5f,            1.0f,  1.0f),
		Vertex(       0.5f, -0.5f,  0.5f,            1.0f,  0.0f),

		// Bottom face				          
		Vertex(       -0.5f, -0.5f, -0.5f,           0.0f,  0.0f),
		Vertex(       0.5f, -0.5f, -0.5f,            1.0f,  0.0f),
		Vertex(       0.5f, -0.5f,  0.5f,            1.0f,  1.0f),
		Vertex(       -0.5f, -0.5f,  0.5f,           0.0f,  1.0f),

		// Top face					          
		Vertex(       -0.5f,  0.5f, -0.5f,           0.0f,  0.0f),
		Vertex(       -0.5f,  0.5f,  0.5f,           0.0f,  1.0f),
		Vertex(       0.5f,  0.5f,  0.5f,            1.0f,  1.0f),
		Vertex(       0.5f,  0.5f, -0.5f,            1.0f,  0.0f),
	};


	std::vector<unsigned int> indices = {
		// Front face
		0, 1, 2,  0, 2, 3,

		// Back face
		4, 5, 6,  4, 6, 7,

		// Left face
		8, 9, 10, 8, 10, 11,

		// Right face
		12, 13, 14, 12, 14, 15,

		// Bottom face
		16, 17, 18, 16, 18, 19,

		// Top face
		20, 21, 22, 20, 22, 23
	};

	Mesh mesh(vertices, indices);
	GameObject testCube("Cube");
	GameObject* cube = GameObject::FindGameObjectWithName("Cube");

	Transform* cubeTransform = cube->AddComponent<Transform>();

	MeshRenderer* cubeRenderer = cube->AddComponent<MeshRenderer>();
	cubeRenderer->SetMesh(&mesh);
	cubeRenderer->SetTexture(texture);
	cubeRenderer->shaderProgram = shaderProgram;


	GameObject camera("Camera");

	Transform* cameraTransform = camera.AddComponent<Transform>();
	cameraTransform->position = glm::vec3(0.0f, 0.0f, 5.0f);

	Camera* cameraComponent = camera.AddComponent<Camera>();
	Camera::main = cameraComponent;


	window->EnableDepthBuffer();

	while (!window->ShouldClose()) {
		window->ProcessInput();

		window->ClearColor(0.5f, 0.8f, 0.9f, 1.0f);
		window->ClearDepthBuffer();

		camera.EarlyUpdate();

		cubeTransform->position = glm::vec3(glm::sin(20.0f * glm::radians(RenderingAPI::GetTime())), 0.0f, 0.0f);
		cameraTransform->position = glm::vec3(1.0f, glm::sin(20.0f * glm::radians(RenderingAPI::GetTime())), 5.0f);

		shaderProgram->Activate();
		
		shaderProgram->SetUniform("viewProjectionMatrix", cameraComponent->GetViewProjectionMatrix());

		cube->Update();

		window->SwapBuffers();
		window->PollEvents();
	}

	delete shaderProgram;
	delete window;
	delete texture;

	RenderingAPI::Terminate();

	return 0;
}
