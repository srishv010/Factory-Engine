#pragma once

#include <string>
#include <vector>

#include <glad/glad.h>

#include "Core.h"
#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			class FACTORY_API ShaderProgram {
			public:
				virtual void AddSource(std::string source, ShaderType type) = 0;
				virtual void Compile() = 0;
				virtual void Activate() = 0;
				virtual void Deactivate() = 0;
			};

			namespace OpenGL {

				class FACTORY_API GLShaderProgram : public ShaderProgram {
				public:
					unsigned int index;

					GLShaderProgram();
					~GLShaderProgram();
					void AddSource(std::string source, ShaderType type) override;
					void Compile() override;
					void Activate() override;
					void Deactivate() override;
				};

			}

		}

	}

}
