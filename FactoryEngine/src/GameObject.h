#pragma once

#include <vector>
#include <string>

#include <glm/glm.hpp>

#include "Core.h"


namespace Factory {

	namespace FactoryEngine {

		class FACTORY_API Component;

		class FACTORY_API Transform;

		class FACTORY_API GameObject {
		private:
			static std::vector<GameObject*> gameObjects;
			std::vector<Component*> components;
			std::vector<GameObject*> children;
			GameObject* parent = nullptr;
			Transform* transform = nullptr;
		public:
			std::string name;

			GameObject(std::string name);
			~GameObject();

			static GameObject* FindGameObjectWithName(const char* name);

			void EarlyUpdate();
			void Update();
			template <typename T> T* AddComponent() {
				T* component = new T();
				if (dynamic_cast<Transform*>(component))
					transform = dynamic_cast<Transform*>(component);
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
			Transform* GetTransform();
			template <typename T> void RemoveComponent() {
				for (Component* component : components) {
					if (dynamic_cast<T*>(component)) {
						if (dynamic_cast<Transform*>(component))
							transform = nullptr;
						delete component;
					}
				}
			}
			int GetChildCount();
			GameObject* GetChild(int index);
			void AddChild(GameObject* child);
			void RemoveChild(GameObject* child);
			GameObject* RemoveChild(int index);
			void SetParent(GameObject* parent);
			GameObject* GetParent();
		};

		class FACTORY_API Component { // private destructor and constructor - only used by GameObject
			friend class GameObject;
		public:
			GameObject* gameObject = nullptr;
		private:
			virtual void OnCreate();
			virtual void EarlyUpdate();
			virtual void Update();
		};

	}

}
