#pragma once

#include <string>
#include <vector>

#include "RenderAPIDataTypes.h"


namespace RenderAPIInterface {

	class ShaderProgram {
	public:
		virtual void AddSource(std::string source, ShaderType type) = 0;
		virtual void Compile() = 0;
		virtual void Activate() = 0;
		virtual void Deactivate() = 0;
	};

}
