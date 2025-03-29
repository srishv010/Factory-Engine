#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

#include "RenderAPIDataTypes.h"
#include "IShader.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

	class GLShaderProgram : public ShaderProgram {
	public:
		unsigned int index;

		GLShaderProgram();
		~GLShaderProgram();
		void AddSource(std::string source, ShaderType type) override;
		void Compile() override;
		void Activate() override;
		void Deactivate() override;

		void SetUniform(std::string name, glm::mat4 value) override;
	};

}
