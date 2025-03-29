#pragma once

#include <glad/glad.h>

#include "RenderAPIDataTypes.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

	GLenum ToGLBoolean(bool value);

	GLenum ToGLDataType(DataType type);

	GLenum ToGLBufferType(BufferType type);

	GLenum ToGLBufferUsagePattern(BufferUsagePattern usagePattern);

	GLenum ToGLPrimitiveType(PrimitiveType type);

	GLenum ToGLShaderType(ShaderType type);

}