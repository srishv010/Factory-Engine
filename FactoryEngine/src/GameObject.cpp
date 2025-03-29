#include "GameObject.h"


namespace Factory {

	namespace FactoryEngine {

		GameObject::GameObject(std::string name) : name(name) { }

		GameObject::~GameObject() {
			for (Component* component : components) {
				delete component;
			}
		}

		void GameObject::EarlyUpdate() {
			for (Component* component : components) {
				component->EarlyUpdate();
			}
		}

		void GameObject::Update() {
			for (Component* component : components) {
				component->Update();
			}
		}

		void Component::OnCreate() { }

		void Component::EarlyUpdate() { }

		void Component::Update() { }

	}

}
