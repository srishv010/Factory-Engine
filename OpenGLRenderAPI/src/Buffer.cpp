#include "Buffer.h"
#include "GLRenderAPIDataTypes.h"


namespace GLRenderAPI {

	GLBuffer::GLBuffer(BufferType type, BufferUsagePattern usagePattern)
		: type(ToGLBufferType(type)), 
		usagePattern(ToGLBufferUsagePattern(usagePattern)) {
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
