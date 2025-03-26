#include "Shader.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <glad/glad.h>


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			namespace OpenGL {

				GLShaderProgram::GLShaderProgram() {
					index = glCreateProgram();
				}

				GLShaderProgram::~GLShaderProgram() {
					glDeleteProgram(index);
				}

				void GLShaderProgram::AddSource(std::string source, ShaderType type) {
					const char* src = source.c_str();
					unsigned int shader = glCreateShader(ToGLShaderType(type));
					glShaderSource(shader, 1, &src, NULL);
					glCompileShader(shader);

					int success;
					glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
					if (!success) {
						char infoLog[512];
						glGetShaderInfoLog(shader, 512, NULL, infoLog);
						std::cout << "ERROR::SHADER::" << ((type == ShaderType::VERTEX_SHADER) ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
					}

					glAttachShader(index, shader);
				}
				
				void GLShaderProgram::Compile() {
					glLinkProgram(index);
					
					int success;
					glGetProgramiv(index, GL_LINK_STATUS, &success);
					if (!success) {
						char infoLog[512];
						glGetProgramInfoLog(index, 512, NULL, infoLog);
						std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
					}
				}

				void GLShaderProgram::Activate() {
					glUseProgram(index);
				}

				void GLShaderProgram::Deactivate() {
					glUseProgram(0);
				}

			}

		}

	}

}
