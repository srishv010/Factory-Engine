#pragma once

#include "glad/glad.h"

#include "RenderAPIDataTypes.h"
#include "IRenderAPI.h"
#include "Window.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

	class GLRenderingAPI : public IRenderAPI {
	public:
		GLWindow* CreateWindow(int width, int height, const char* title);
		GLVertexArray* CreateVertexArray(std::vector<VertexArrayAttribute> attributes);
		GLBuffer* CreateBuffer(BufferType type, BufferUsagePattern usagePattern);
		GLShaderProgram* CreateShaderProgram();

		void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices);
	};

}
