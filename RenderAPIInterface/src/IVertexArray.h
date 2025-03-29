#pragma once

#include <vector>

#include "RenderAPIDataTypes.h"


namespace RenderAPIInterface {

	struct VertexArrayAttribute {
		unsigned int index;
		int size;
		DataType type;
		bool normalized;
		int stride;
		const void* pointer;

		VertexArrayAttribute(
			unsigned int index,
			int size,
			DataType type,
			bool normalized,
			int stride,
			const void* pointer)
			: index(index),
			size(size), type(type),
			normalized(normalized),
			stride(stride),
			pointer(pointer) { }
	};

	class VertexArray {
	public:
		std::vector<VertexArrayAttribute> attributes;

		VertexArray(std::vector<VertexArrayAttribute> attributes)
			: attributes(attributes) { }
		virtual void AddAttribute(VertexArrayAttribute attribute) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};

}
