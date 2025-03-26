#pragma once

#include <vector>

#include "Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"
#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			class FACTORY_API RenderingAPI {
			public:
				static RenderAPIType apiType;
				static VertexArray* CreateVertexArray(std::vector<VertexArrayAttribute> attributes);
				static Buffer* CreateBuffer(BufferType type, BufferUsagePattern usagePattern);
				static ShaderProgram* CreateShaderProgram();

				static void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices);
			};

		}

	}

}
