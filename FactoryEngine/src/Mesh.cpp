#include "Mesh.h"


namespace Factory {

	namespace FactoryEngine {

		Vertex::Vertex(float x, float y, float z) : position(x, y, z) { }
		Vertex::Vertex(glm::vec3 position) : position(position) { }
		Vertex::Vertex() : position(0.0f, 0.0f, 0.0f) { }

		Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) : vertices(vertices), indices(indices) { }

	}

}
