#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Core.h"
#include "GameObject.h"


namespace Factory {

	namespace FactoryEngine {

		class FACTORY_API Transform : public Component {
			friend class GameObject;
		public:
			glm::vec3 position = glm::vec3(0.0f);
			glm::quat rotation = glm::quat(glm::vec3(0.0f));
			glm::vec3 scale = glm::vec3(1.0f);

			~Transform();

			glm::mat4 GetModelMatrix();
		};

	}

}
