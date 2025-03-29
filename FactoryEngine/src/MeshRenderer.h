#pragma once

#include "Core.h"
#include "Mesh.h"

#include "RenderAPI.h"

namespace Factory {

	namespace FactoryEngine {


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

		class FACTORY_API MeshRenderer {
		private:
			LowLevelGraphics::MeshRenderData* meshRenderData;
		public:
			MeshRenderer(Mesh* meshData);
			~MeshRenderer();
			void Render();
		};

	}

}
