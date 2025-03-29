#pragma once

#include <vector>
#include <string>

#include <glm/glm.hpp>

#include "Core.h"


namespace Factory {
	namespace FactoryEngine {

		class FACTORY_API Component;

		class FACTORY_API GameObject {
		public:
			std::string name;
			std::vector<Component*> components;

			GameObject(std::string name);
			~GameObject();

			void Update();
			template <typename T> T* AddComponent() {
				T* component = new T();
				component->gameObject = this;
				components.push_back(component);
				component->OnCreate();
				return component;
			}
			template <typename T> T* GetComponent() {
				for (Component* component : components) {
					if (dynamic_cast<T*>(component)) {
						return dynamic_cast<T*>(component);
					}
				}
				return nullptr;
			}
			template <typename T> void RemoveComponent() {
				for (Component* component : components) {
					if (dynamic_cast<T*>(component)) {
						delete component;
					}
				}
			}
		};

		class FACTORY_API Component {
			friend class GameObject;
		public:
			GameObject* gameObject = nullptr;
		private:
			virtual void OnCreate();
			virtual void Update();
		};

	}
}
