#pragma once

#include "Core.h"
#include "IRenderAPI.h"


namespace Factory {
	
	namespace FactoryEngine {

		namespace RenderAPI {

			using namespace RenderAPIInterface;

			class FACTORY_API RenderingAPI {
			public:
				static IRenderAPI* renderAPI;

				RenderingAPI() = delete;
				~RenderingAPI() = delete;

				static void Initialize(const char* renderAPIName);
				static void Terminate();
				static Window* CreateWindow(int width, int height, const char* title);
				static VertexArray* CreateVertexArray(std::vector<VertexArrayAttribute> attributes);
				static Buffer* CreateBuffer(BufferType type, BufferUsagePattern usagePattern);
				static ShaderProgram* CreateShaderProgram();

				static void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices);
			};

		}

	}
}
