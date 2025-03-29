#pragma once

#include <iostream>


namespace RenderAPIInterface {

	class Window {
	public:
		virtual void ProcessInput() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
		virtual bool ShouldClose() = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual float GetAspectRatio() = 0;
	};

}
