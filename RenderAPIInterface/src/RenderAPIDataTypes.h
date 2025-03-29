#pragma once


namespace RenderAPIInterface {

	enum class RenderAPIType {
		OPEN_GL
	};

	enum class DataType {
		BYTE,
		UNSIGNED_BYTE,
		SHORT,
		UNSIGNED_SHORT,
		INT,
		UNSIGNED_INT,
		FLOAT
	};



	enum BufferType {
		ARRAY_BUFFER,
		ELEMENT_ARRAY_BUFFER
	};

	enum class BufferUsagePattern {
		STATIC_DRAW,
		DYNAMIC_DRAW
	};

	enum class PrimitiveType {
		POINTS,
		LINES,
		LINE_LOOP,
		LINE_STRIP,
		TRIANGLES,
		TRIANGLE_STRIP,
		TRIANGLE_FAN
	};

	enum class ShaderType {
		VERTEX_SHADER,
		FRAGMENT_SHADER
	};

}
