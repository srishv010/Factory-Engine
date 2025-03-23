#pragma once

#include <vector>

#include "VertexArray.h"
#include "Buffer.h"
#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			class RenderingAPI {
			public:
				static RenderAPIType apiType;
				static VertexArray* CreateVertexArray(std::vector<VertexArrayAttribute> attributes);
				static Buffer* CreateBuffer(BufferType type, BufferUsagePattern usagePattern);
				static void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices);
			};

		}

	}

}
