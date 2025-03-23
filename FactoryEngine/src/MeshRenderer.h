#pragma once

#include "Core.h"
#include "Mesh.h"

#include "VertexArray.h"
#include "Buffer.h"


namespace Factory {

	namespace FactoryEngine {

		using namespace RenderAPI;
		using namespace OpenGL;

		namespace LowLevelGraphics {

			class FACTORY_API MeshRenderData {
			public:
				GLVertexArray* vertexArray;
				GLBuffer* vertexBuffer;
				GLBuffer* indexBuffer;
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
