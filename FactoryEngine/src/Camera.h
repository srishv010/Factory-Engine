#pragma once

#include <glm/glm.hpp>

#include "Core.h"
#include "GameObject.h"
#include "Transform.h"


namespace Factory {

	namespace FactoryEngine {

		class FACTORY_API Camera : public Component {
			friend class GameObject;
		private:
			Transform* transform = nullptr;

			void OnCreate() override;
		public:
			float fieldOfView = 45.0f;
			float nearPlane = 0.1f;
			float farPlane = 100.0f;

			static Camera* main;
			glm::mat4 GetViewProjectionMatrix(); 
		};

	}

}
