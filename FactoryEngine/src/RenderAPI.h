#pragma once

#include "Core.h"
#include "IRenderAPI.h"

#include "GLRenderAPI.h"

using namespace RenderAPIInterface;

namespace Factory {
	
	namespace FactoryEngine {

		namespace RenderAPI {

			class FACTORY_API RenderingAPI {
			public:
				static IRenderAPI* renderAPI;

				RenderingAPI() { };
				~RenderingAPI() {
					delete renderAPI;
				}

				static void Initialize() {
					renderAPI = new GLRenderAPI::GLRenderingAPI();
				}

				static Window* CreateWindow(int width, int height, const char* title) {
					return renderAPI->CreateWindow(width, height, title);
				}

				static VertexArray* CreateVertexArray(std::vector<VertexArrayAttribute> attributes) {
					return renderAPI->CreateVertexArray(attributes);
				}

				static Buffer* CreateBuffer(BufferType type, BufferUsagePattern usagePattern) {
					return renderAPI->CreateBuffer(type, usagePattern);
				}

				static ShaderProgram* CreateShaderProgram() {
					return renderAPI->CreateShaderProgram();
				}


				static void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices) {
					renderAPI->DrawElements(primitive, count, type, indices);
				}
			};

		}

	}
}
