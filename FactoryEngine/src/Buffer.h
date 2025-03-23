#pragma once

#include <glad/glad.h>

#include "Core.h"
#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			class FACTORY_API Buffer {
			public:
				Buffer(BufferType type, BufferUsagePattern usagePattern);
				virtual void SetData(void* data, size_t size) = 0;
				virtual void Bind() = 0;
				virtual void Unbind() = 0;
			};

			namespace OpenGL {

				class GLBuffer : public Buffer {
				public:
					unsigned int index;
					GLenum type;
					GLenum usagePattern;

					GLBuffer(BufferType type, BufferUsagePattern usagePattern);
					~GLBuffer();

					void SetData(void* data, size_t size) override;
					void Bind() override;
					void Unbind() override;
				};

			}

		}

	}

}