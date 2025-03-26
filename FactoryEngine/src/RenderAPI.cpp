#include "RenderAPI.h"

#include "GLRenderAPI.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			RenderAPIType RenderingAPI::apiType = RenderAPIType::OPEN_GL;
			VertexArray* RenderingAPI::CreateVertexArray(std::vector<VertexArrayAttribute> attributes) {
				switch (apiType) {
				case RenderAPIType::OPEN_GL:
					return new OpenGL::GLVertexArray(attributes);
				default:
					return nullptr;
				}
			}
			Buffer* RenderingAPI::CreateBuffer(BufferType type, BufferUsagePattern usagePattern) {
				switch (apiType) {
				case RenderAPIType::OPEN_GL:
					return new OpenGL::GLBuffer(type, usagePattern);
				default:
					return nullptr;
				}
			}

			ShaderProgram* RenderingAPI::CreateShaderProgram()
			{
				switch (apiType) {
				case RenderAPIType::OPEN_GL:
					return new OpenGL::GLShaderProgram();
				default:
					return nullptr;
				}
			}

			void RenderingAPI::DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices)
			{
				switch (apiType) {
				case RenderAPIType::OPEN_GL:
					OpenGL::GLRenderingAPI::DrawElements(primitive, count, type, indices);
					break;
				default:
					break;
				}
			}

		}

	}

}
