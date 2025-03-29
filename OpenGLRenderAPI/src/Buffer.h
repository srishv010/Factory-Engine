#pragma once

#include <glad/glad.h>

#include "RenderAPIDataTypes.h"
#include "IBuffer.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

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