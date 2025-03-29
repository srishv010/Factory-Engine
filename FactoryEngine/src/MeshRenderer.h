#pragma once

#include "Core.h"
#include "GameObject.h"
#include "Mesh.h"

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
			void Update() override;
		public:
			~MeshRenderer();
			void SetMesh(Mesh* meshData);
			void Render();
		};

	}

}
