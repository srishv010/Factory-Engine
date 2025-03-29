#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IWindow.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

		class GLWindow : public Window {
			public:
				const char* title;
				GLFWwindow* window;

				GLWindow(int width, int height, const char* title);
				~GLWindow();
				void ProcessInput() override;
				void SwapBuffers() override;
				void PollEvents() override;
				bool ShouldClose() override;
				void ClearColor(float r, float g, float b, float a) override;

				int GetWidth() override;
				int GetHeight() override;
				float GetAspectRatio() override;
		};
}
