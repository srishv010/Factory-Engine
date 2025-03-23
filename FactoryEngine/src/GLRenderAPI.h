#pragma once

#include "glad/glad.h"

#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				class GLRenderingAPI {
				public:
					static void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices);
				};

			}

		}

	}

}
