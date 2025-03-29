#pragma once

#include <vector>

#include <glad/glad.h>

#include "RenderAPIDataTypes.h"
#include "IVertexArray.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {
	
	class GLVertexArray : public VertexArray {
	public:
		unsigned int index;
		std::vector<VertexArrayAttribute> attributes;

		GLVertexArray(std::vector<VertexArrayAttribute> attributes);
		~GLVertexArray();

		void AddAttribute(VertexArrayAttribute attribute) override;
		void Bind() override;
		void Unbind() override;
	};

}
