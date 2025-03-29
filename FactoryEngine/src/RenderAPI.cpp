#include "RenderAPI.h"

#include <windows.h>
#undef CreateWindow


namespace Factory {
	
	namespace FactoryEngine {

		namespace RenderAPI {

			IRenderAPI* RenderingAPI::renderAPI = nullptr;
			Window* RenderingAPI::window = nullptr;

			void RenderingAPI::Initialize(const char* renderAPIName) {
				if (renderAPI != nullptr) return;
				std::string renderAPINameStr = std::string(renderAPIName) + ".dll";
				HMODULE renderAPIModule = LoadLibraryA(renderAPINameStr.c_str());
				if (!renderAPIModule) {
					std::cout << "Failed to load render API module" << std::endl;
					return;
				}

				typedef IRenderAPI* (*CreateRenderAPIFunc)();
				CreateRenderAPIFunc GetRenderAPI = (CreateRenderAPIFunc)GetProcAddress(renderAPIModule, "CreateRenderAPI");

				if (!GetRenderAPI) {
					DWORD error = GetLastError();
					std::cout << "GetProcAddress failed! Error code: " << error << std::endl;
					return;
				}

				renderAPI = GetRenderAPI();
			}

			void RenderingAPI::Terminate() {
				delete renderAPI;
			}

			Window* RenderingAPI::CreateWindow(int width, int height, const char* title)
			{
				window = renderAPI->CreateWindow(width, height, title);
				return window;
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

			double RenderingAPI::GetTime()
			{
				return renderAPI->GetTime();
			}

		}

	}
}
