#include "Mesh.h"


namespace Factory {

	namespace FactoryEngine {

		Vertex::Vertex(float x, float y, float z, float u, float v) : position(x, y, z), uvs(u, v) { }
		Vertex::Vertex(glm::vec3 position, glm::vec2 uvs) : position(position), uvs(uvs) { }
		Vertex::Vertex() : position(0.0f, 0.0f, 0.0f), uvs(0.0f, 0.0f) { }

		Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) : vertices(vertices), indices(indices) { }

	}

}
