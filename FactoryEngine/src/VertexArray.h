#pragma once

#include <vector>

#include <glad/glad.h>

#include "Core.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				struct FACTORY_API VertexArrayAttribute {
					unsigned int index;
					int size;
					GLenum type;
					GLboolean normalized;
					int stride;
					const void* pointer;

					VertexArrayAttribute(
						unsigned int index,
						int size,
						GLenum type,
						GLboolean normalized,
						int stride,
						const void* pointer);
				};

				class FACTORY_API GLVertexArray {
				public:
					unsigned int index;
					std::vector<VertexArrayAttribute> attributes;

					GLVertexArray(std::vector<VertexArrayAttribute> attributes);
					~GLVertexArray();

					void AddAttribute(VertexArrayAttribute attribute);
					void Bind();
					void Unbind();
				};

			}

		}

	}

}
