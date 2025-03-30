#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "Core.h"

namespace Factory
{

	namespace FactoryEngine {

		struct FACTORY_API Vertex {
			glm::vec3 position;
			glm::vec2 uvs;

			Vertex(float x, float y, float z, float u, float v);
			Vertex(glm::vec3 position, glm::vec2 uvs);
			Vertex();
		};

		struct FACTORY_API Mesh {
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;

			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
		};

	}

}
