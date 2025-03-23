#include "VertexArray.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				VertexArrayAttribute::VertexArrayAttribute(
					unsigned int index,
					int size,
					GLenum type,
					GLboolean normalized,
					int stride,
					const void* pointer)
					: index(index),
					size(size),
					type(type),
					normalized(normalized),
					stride(stride),
					pointer(pointer) { }


				GLVertexArray::GLVertexArray(std::vector<VertexArrayAttribute> attributes) {
					glGenVertexArrays(1, &index);
					glBindVertexArray(index);
					for (VertexArrayAttribute attribute : attributes) {
						glVertexAttribPointer(attribute.index, attribute.size, attribute.type, attribute.normalized, attribute.stride, attribute.pointer);
						glEnableVertexAttribArray(attribute.index);
					}
					glBindVertexArray(0);
				}

				GLVertexArray::~GLVertexArray() {
					glDeleteVertexArrays(1, &index);
				}

				void GLVertexArray::AddAttribute(VertexArrayAttribute attribute) {
					Bind();
					glVertexAttribPointer(attribute.index, attribute.size, attribute.type, attribute.normalized, attribute.stride, attribute.pointer);
					glEnableVertexAttribArray(attribute.index);
					Unbind();
				}

				void GLVertexArray::Bind() {
					glBindVertexArray(index);
				}

				void GLVertexArray::Unbind() {
					glBindVertexArray(0);
				}

			}

		}

	}

}
