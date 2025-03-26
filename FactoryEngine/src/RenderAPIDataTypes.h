#pragma once

#include <glad/glad.h>

#include "Core.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			enum class RenderAPIType {
				OPEN_GL
			};

			enum class FACTORY_API DataType {
				BYTE,
				UNSIGNED_BYTE,
				SHORT,
				UNSIGNED_SHORT,
				INT,
				UNSIGNED_INT,
				FLOAT
			};



			enum FACTORY_API BufferType {
				ARRAY_BUFFER,
				ELEMENT_ARRAY_BUFFER
			};

			enum class FACTORY_API BufferUsagePattern {
				STATIC_DRAW,
				DYNAMIC_DRAW
			};

			enum class FACTORY_API PrimitiveType {
				POINTS,
				LINES,
				LINE_LOOP,
				LINE_STRIP,
				TRIANGLES,
				TRIANGLE_STRIP,
				TRIANGLE_FAN
			};

			enum class FACTORY_API ShaderType {
				VERTEX_SHADER,
				FRAGMENT_SHADER
			};

			namespace OpenGL {

				GLenum ToGLBoolean(bool value);

				GLenum ToGLDataType(DataType type);

				GLenum ToGLBufferType(BufferType type);

				GLenum ToGLBufferUsagePattern(BufferUsagePattern usagePattern);

				GLenum ToGLPrimitiveType(PrimitiveType type);

				GLenum ToGLShaderType(ShaderType type);

			}
		}
	}
}
