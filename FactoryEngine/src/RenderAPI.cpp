#include "RenderAPI.h"


namespace Factory {
	
	namespace FactoryEngine {

		namespace RenderAPI {

			IRenderAPI* RenderingAPI::renderAPI = nullptr;

			void RenderingAPI::Initialize() {
				if (renderAPI == nullptr)
					renderAPI = CreateRenderAPI();
			}

			void RenderingAPI::Terminate() {
				delete renderAPI;
			}

			Window* RenderingAPI::CreateWindow(int width, int height, const char* title)
			{
				return renderAPI->CreateWindow(width, height, title);
			}

			VertexArray* RenderingAPI::CreateVertexArray(std::vector<VertexArrayAttribute> attributes)
			{
				return renderAPI->CreateVertexArray(attributes);
			}

			Buffer* RenderingAPI::CreateBuffer(BufferType type, BufferUsagePattern usagePattern)
			{
				return renderAPI->CreateBuffer(type, usagePattern);
			}

			ShaderProgram* RenderingAPI::CreateShaderProgram()
			{
				return renderAPI->CreateShaderProgram();
			}

			void RenderingAPI::DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices)
			{
				renderAPI->DrawElements(primitive, count, type, indices);
			}

		}

	}
}
