#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				GLenum ToGLBoolean(bool value)
				{
					return value ? GL_TRUE : GL_FALSE;
				}

				GLenum ToGLDataType(DataType type)
				{
					switch (type) {
					case DataType::BYTE:
						return GL_BYTE;
					case DataType::UNSIGNED_BYTE:
						return GL_UNSIGNED_BYTE;
					case DataType::SHORT:
						return GL_SHORT;
					case DataType::UNSIGNED_SHORT:
						return GL_UNSIGNED_SHORT;
					case DataType::INT:
						return GL_INT;
					case DataType::UNSIGNED_INT:
						return GL_UNSIGNED_INT;
					case DataType::FLOAT:
						return GL_FLOAT;
					default:
						return GL_FLOAT;
					}
				}

				GLenum ToGLBufferType(BufferType type) {
					switch (type) {
					case BufferType::ARRAY_BUFFER:
						return GL_ARRAY_BUFFER;
					case BufferType::ELEMENT_ARRAY_BUFFER:
						return GL_ELEMENT_ARRAY_BUFFER;
					default:
						return 0;
					}
				}

				GLenum ToGLBufferUsagePattern(BufferUsagePattern usagePattern) {
					switch (usagePattern) {
					case BufferUsagePattern::STATIC_DRAW:
						return GL_STATIC_DRAW;
					case BufferUsagePattern::DYNAMIC_DRAW:
						return GL_DYNAMIC_DRAW;
					default:
						return 0;
					}
				}

				GLenum ToGLPrimitiveType(PrimitiveType type)
				{
					switch (type) {
					case PrimitiveType::POINTS:
						return GL_POINTS;
					case PrimitiveType::LINES:
						return GL_LINES;
					case PrimitiveType::LINE_LOOP:
						return GL_LINE_LOOP;
					case PrimitiveType::LINE_STRIP:
						return GL_LINE_STRIP;
					case PrimitiveType::TRIANGLES:
						return GL_TRIANGLES;
					case PrimitiveType::TRIANGLE_STRIP:
						return GL_TRIANGLE_STRIP;
					case PrimitiveType::TRIANGLE_FAN:
						return GL_TRIANGLE_FAN;
					default:
						return GL_TRIANGLES;
					}
				}

			}

		}

	}

}
