#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

#include "RenderAPIDataTypes.h"


namespace RenderAPIInterface {

	class ShaderProgram {
	public:
		virtual void AddSource(std::string source, ShaderType type) = 0;
		virtual void Compile() = 0;
		virtual void Activate() = 0;
		virtual void Deactivate() = 0;

		virtual void SetUniform(std::string name, glm::mat4) = 0;
	};

}
