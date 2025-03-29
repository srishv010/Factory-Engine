#include "VertexArray.h"
#include "GLRenderAPIDataTypes.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

	GLVertexArray::GLVertexArray(std::vector<VertexArrayAttribute> attributes) : VertexArray(attributes) {
		glGenVertexArrays(1, &index);
		glBindVertexArray(index);
		for (VertexArrayAttribute const &attribute : attributes) {
			glVertexAttribPointer(attribute.index, attribute.size, ToGLDataType(attribute.type), ToGLBoolean(attribute.normalized), attribute.stride, attribute.pointer);
			glEnableVertexAttribArray(attribute.index);
		}
		glBindVertexArray(0);
	}

	GLVertexArray::~GLVertexArray() {
		glDeleteVertexArrays(1, &index);
	}

	void GLVertexArray::AddAttribute(VertexArrayAttribute attribute) {
		attributes.push_back(attribute);
		Bind();
		glVertexAttribPointer(attribute.index, attribute.size, ToGLDataType(attribute.type), ToGLBoolean(attribute.normalized), attribute.stride, attribute.pointer);
		glEnableVertexAttribArray(attribute.index);
		Unbind();
	}

	void GLVertexArray::Bind() {
		glBindVertexArray(index);
	}

	void GLVertexArray::Unbind() {
		glBindVertexArray(0);
	}

}
