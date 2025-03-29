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


	std::vector<Vertex> vertices = {
		Vertex( 0.5f,  0.0f,  0.5f),
		Vertex( 0.5f,  0.0f, -0.5f),
		Vertex(-0.5f,  0.0f, -0.5f),
		Vertex(-0.5f,  0.0f,  0.5f)
	};
	std::vector<unsigned int> indices = {
		0, 1, 3,
		1, 2, 3
	};

	Mesh mesh(vertices, indices);
	GameObject rectangle("Rectangle");

	Transform* rectangleTransform = rectangle.AddComponent<Transform>();

	MeshRenderer* rectangleRenderer = rectangle.AddComponent<MeshRenderer>();
	rectangleRenderer->SetMesh(&mesh);
	rectangleRenderer->shaderProgram = shaderProgram;


	GameObject camera("Camera");

	Transform* cameraTransform = camera.AddComponent<Transform>();
	cameraTransform->position = glm::vec3(0.0f, 0.0f, 5.0f);

	Camera* cameraComponent = camera.AddComponent<Camera>();
	Camera::main = cameraComponent;




	while (!window->ShouldClose()) {
		window->ProcessInput();

		window->ClearColor(0.5f, 0.8f, 0.9f, 1.0f);

		camera.EarlyUpdate();

		rectangleTransform->position = glm::vec3(glm::sin(20.0f * glm::radians(RenderingAPI::GetTime())), 0.0f, 0.0f);
		cameraTransform->position = glm::vec3(0.0f, glm::sin(20.0f * glm::radians(RenderingAPI::GetTime())), 5.0f);

		shaderProgram->Activate();

		shaderProgram->SetUniform("viewProjectionMatrix", cameraComponent->GetViewProjectionMatrix());

		rectangle.Update();

		window->SwapBuffers();
		window->PollEvents();
	}

	delete shaderProgram;
	delete window;

	RenderingAPI::Terminate();

	return 0;
}
