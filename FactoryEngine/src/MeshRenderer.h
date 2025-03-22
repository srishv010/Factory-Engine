#pragma once

#include "Core.h"
#include "Mesh.h"


namespace Factory {

	namespace FactoryEngine {

		namespace LowLevelGraphics {

			class FACTORY_API MeshRenderData {
			public:
				unsigned int vertexArray, vertexBuffer, indexBuffer;
				Mesh* meshData;

				MeshRenderData(Mesh* meshData);
				~MeshRenderData();
				void TransferData();
				void Render();

			};

		}

	}

}
