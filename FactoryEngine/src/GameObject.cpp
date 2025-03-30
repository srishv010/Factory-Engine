#include "GameObject.h"


namespace Factory {

	namespace FactoryEngine {

		std::vector<GameObject*> GameObject::gameObjects = std::vector<GameObject*>();

		GameObject::GameObject(std::string name) : name(name) {
			gameObjects.push_back(this);
		}

		GameObject::~GameObject() {
			for (Component* component : components) {
				delete component;
			}
		}

		GameObject* GameObject::FindGameObjectWithName(const char* name) {
			for (GameObject* gameObject : gameObjects) {
				if (gameObject->name == name) {
					return gameObject;
				}
			}
			return nullptr;
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

		Transform* GameObject::GetTransform()
		{
			return transform;
		}

		int GameObject::GetChildCount() {
			return children.size();
		}

		GameObject* GameObject::GetChild(int index) {
			return children[index];
		}

		void GameObject::AddChild(GameObject* child) {
			children.push_back(child);
			child->parent = this;
		}

		void GameObject::RemoveChild(GameObject* child) {
			for (int i = 0; i < children.size(); i++) {
				if (children[i] == child) {
					children.erase(children.begin() + i);
					return;
				}
			}
		}

		GameObject* GameObject::RemoveChild(int index) {
			GameObject* child = children[index];
			children.erase(children.begin() + index);
			return child;
		}

		void GameObject::SetParent(GameObject* parent) {
			if (this->parent != nullptr)
				this->parent->RemoveChild(this);
			this->parent = parent;
			if (parent != nullptr)
				parent->AddChild(this);
		}

		GameObject* GameObject::GetParent() {
			return parent;
		}

		void Component::OnCreate() { }

		void Component::EarlyUpdate() { }

		void Component::Update() { }

	}

}
