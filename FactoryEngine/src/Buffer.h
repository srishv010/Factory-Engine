#pragma once

#include <glad/glad.h>

#include "Core.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				class FACTORY_API GLBuffer {
				public:
					unsigned int index;
					GLenum type;
					GLenum usagePattern;

					GLBuffer(GLenum type, GLenum usagePattern);
					~GLBuffer();

					void SetData(void* data, size_t size);
					void Bind();
					void Unbind();
				};

			}

		}

	}

}