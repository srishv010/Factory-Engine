#include "Camera.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "RenderAPI.h"


namespace Factory {

	namespace FactoryEngine {

		Camera* Camera::main = nullptr;

		void Camera::OnCreate() {
			transform = gameObject->GetComponent<Transform>();
			if (transform == nullptr)
				transform = gameObject->AddComponent<Transform>();
		}

		glm::mat4 Camera::GetViewProjectionMatrix() {
			glm::mat4 rotatingMatrix = glm::mat4_cast(glm::conjugate(transform->rotation));
			glm::mat4 translatingMatrix = glm::translate(glm::mat4(1.0f), -transform->position);
			glm::mat4 viewMatrix = translatingMatrix * rotatingMatrix;

			glm::mat4 projectionMatrix = glm::perspective(glm::radians(fieldOfView), RenderAPI::RenderingAPI::window->GetAspectRatio(), nearPlane, farPlane);
			return projectionMatrix * viewMatrix;
		}

	}

}
