#pragma once

#include "Core.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Transform.h"

#include "RenderAPI.h"

namespace Factory {

	namespace FactoryEngine {

		using namespace RenderAPI;

		namespace LowLevelGraphics {

			class FACTORY_API MeshRenderData {
			public:
				VertexArray* vertexArray;
				Buffer* vertexBuffer;
				Buffer* indexBuffer;
				Mesh* meshData;

				MeshRenderData(Mesh* meshData);
				~MeshRenderData();
				void TransferData();
				void Render();
			};

		}

		class FACTORY_API MeshRenderer : public Component {
			friend class GameObject;
		private:
			LowLevelGraphics::MeshRenderData* meshRenderData = nullptr;
			Transform* transform = nullptr;
			Texture* texture = nullptr;

			void OnCreate() override;
			void Update() override;
		public:
			ShaderProgram* shaderProgram = nullptr;

			~MeshRenderer();
			void SetMesh(Mesh* meshData);
			void SetTexture(Texture* texture);
			void Render();
		};

	}

}
