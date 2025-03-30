#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>


namespace Factory {

	namespace FactoryEngine {

		Transform::~Transform () { }

		glm::mat4 Transform::GetModelMatrix() {
			glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), GetWorldScale());
			glm::mat4 rotatingMatrix = glm::mat4_cast(GetWorldRotation());
			glm::mat4 translatingMatrix = glm::translate(glm::mat4(1.0f), GetWorldPosition());
			glm::mat4 modelMatrix = translatingMatrix * rotatingMatrix * scalingMatrix;

			return modelMatrix;
		}

		glm::vec3 Transform::GetWorldPosition() {
			if (gameObject->GetParent() == nullptr)	return position;
			return position + gameObject->GetParent()->GetTransform()->GetWorldPosition();
		}

		glm::quat Transform::GetWorldRotation() {
			if (gameObject->GetParent() == nullptr)	return rotation;
			return rotation * gameObject->GetParent()->GetTransform()->GetWorldRotation();
		}

		glm::vec3 Transform::GetWorldScale() {
			if (gameObject->GetParent() == nullptr)	return scale;
			return scale * gameObject->GetParent()->GetTransform()->GetWorldScale();
		}

	}

}
