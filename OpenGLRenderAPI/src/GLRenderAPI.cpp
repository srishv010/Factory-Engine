#include "GLRenderAPI.h"

#include <GLFW/glfw3.h>

#include "GLRenderAPIDataTypes.h"


namespace GLRenderAPI {


	GLWindow* GLRenderingAPI::CreateWindow(int width, int height, const char* title) {
		return new GLWindow(width, height, title);
	}

	GLVertexArray* GLRenderingAPI::CreateVertexArray(std::vector<VertexArrayAttribute> attributes) {
		return new GLVertexArray(attributes);
	}
	GLBuffer* GLRenderingAPI::CreateBuffer(BufferType type, BufferUsagePattern usagePattern) {
		return new GLBuffer(type, usagePattern);
	}
	GLShaderProgram* GLRenderingAPI::CreateShaderProgram() {
		return new GLShaderProgram();
	}

	void GLRenderingAPI::DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices) {
		glDrawElements(ToGLPrimitiveType(primitive), count, ToGLDataType(type), indices);
	}

	double GLRenderingAPI::GetTime() {
		return glfwGetTime();
	}

}
