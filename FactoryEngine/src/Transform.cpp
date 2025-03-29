#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>


namespace Factory {

	namespace FactoryEngine {

		Transform::~Transform () { }

		glm::mat4 Transform::GetModelMatrix() {
			glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);
			glm::mat4 rotatingMatrix = glm::mat4_cast(rotation);
			glm::mat4 translatingMatrix = glm::translate(glm::mat4(1.0f), position);
			glm::mat4 modelMatrix = translatingMatrix * rotatingMatrix * scalingMatrix;

			return modelMatrix;
		}

	}

}
