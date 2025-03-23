#include "VertexArray.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			VertexArrayAttribute::VertexArrayAttribute(
				unsigned int index,
				int size,
				DataType type,
				bool normalized,
				int stride,
				const void* pointer)
				: index(index),
				size(size),
				type(type),
				normalized(normalized),
				stride(stride),
				pointer(pointer) {
			}

			VertexArray::VertexArray(std::vector<VertexArrayAttribute> attributes) : attributes(attributes) { }

			namespace OpenGL {

				GLVertexArray::GLVertexArray(std::vector<VertexArrayAttribute> attributes) : VertexArray(attributes) {
					glGenVertexArrays(1, &index);
					glBindVertexArray(index);
					for (VertexArrayAttribute const &attribute : attributes) {
						glVertexAttribPointer(attribute.index, attribute.size, ToGLDataType(attribute.type), ToGLBoolean(attribute.normalized), attribute.stride, attribute.pointer);
						glEnableVertexAttribArray(attribute.index);
					}
					glBindVertexArray(0);
				}

				GLVertexArray::~GLVertexArray() {
					glDeleteVertexArrays(1, &index);
				}

				void GLVertexArray::AddAttribute(VertexArrayAttribute attribute) {
					attributes.push_back(attribute);
					Bind();
					glVertexAttribPointer(attribute.index, attribute.size, ToGLDataType(attribute.type), ToGLBoolean(attribute.normalized), attribute.stride, attribute.pointer);
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
