#include "GLRenderAPI.h"

#include <glad/glad.h>


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				void GLRenderingAPI::DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices) {
					glDrawElements(ToGLPrimitiveType(primitive), count, ToGLDataType(type), indices);
				}
			}
		}
	}
}
