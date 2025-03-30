#pragma once

#include <vector>

#include "IWindow.h"
#include "IVertexArray.h"
#include "IBuffer.h"
#include "IShader.h"
#include "ITexture.h"
#include "RenderAPIDataTypes.h"


namespace RenderAPIInterface {

	class IRenderAPI {
	public:
		virtual Window* CreateWindow(int width, int height, const char* title) = 0;
		virtual VertexArray* CreateVertexArray(std::vector<VertexArrayAttribute> attributes) = 0;
		virtual Buffer* CreateBuffer(BufferType type, BufferUsagePattern usagePattern) = 0;
		virtual ShaderProgram* CreateShaderProgram() = 0;
		virtual Texture* CreateTexture(unsigned char* data, int width, int height, int colorChannels) = 0;

		virtual void DrawElements(PrimitiveType primitive, unsigned int count, DataType type, const void* indices) = 0;
		virtual double GetTime() = 0;
	};


}
