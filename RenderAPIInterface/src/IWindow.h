#pragma once

#include <iostream>


namespace RenderAPIInterface {

	class Window {
	public:
		int width, height;
		const char* title;

		Window(int width, int height, const char* title) : width(width), height(height), title(title) { }
		virtual void ProcessInput() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
		virtual bool ShouldClose() = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;
	};

}
