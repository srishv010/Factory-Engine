#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "Core.h"

namespace Factory
{

	namespace FactoryEngine {

		struct FACTORY_API Vertex {
			glm::vec3 position;

			Vertex(float x, float y, float z);
			Vertex(glm::vec3 position);
			Vertex();
		};

		struct FACTORY_API Mesh {
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;

			unsigned int vertexArray, vertexBuffer, indexBuffer;

			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
		};

	}

}
