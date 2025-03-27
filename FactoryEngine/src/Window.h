#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			class FACTORY_API Window {
			public:
				int width, height;
				const char* title;

				Window(int width, int height, const char* title);
				virtual void ProcessInput() = 0;
				virtual void SwapBuffers() = 0;
				virtual void PollEvents() = 0;
				virtual bool ShouldClose() = 0;
				virtual void ClearColor(float r, float g, float b, float a) = 0;
			};
			namespace OpenGL {
				
				class GLWindow : public Window {
					public:
						GLFWwindow* window;

						GLWindow(int width, int height, const char* title);
						~GLWindow();
						void ProcessInput() override;
						void SwapBuffers() override;
						void PollEvents() override;
						bool ShouldClose() override;
						void ClearColor(float r, float g, float b, float a) override;
				};

			}
		}
	}
}
