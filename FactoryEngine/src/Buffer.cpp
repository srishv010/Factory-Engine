#include "Buffer.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				GLBuffer::GLBuffer(GLenum type, GLenum usagePattern) : type(type), usagePattern(usagePattern) {
					glGenBuffers(1, &index);
				}

				GLBuffer::~GLBuffer() {
					glDeleteBuffers(1, &index);
				}

				void GLBuffer::SetData(void* data, size_t size) {
					Bind();
					glBufferData(type, size, data, usagePattern);
					Unbind();
				}

				void GLBuffer::Bind() {
					glBindBuffer(type, index);
				}

				void GLBuffer::Unbind() {
					glBindBuffer(type, 0);
				}

			}

		}

	}

}
