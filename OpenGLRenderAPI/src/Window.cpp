#include <Window.h>
#include <functional>

namespace GLRenderAPI {

	GLWindow::GLWindow(int width, int height, const char* title)
		: title(title) {
		window = nullptr;

		if (glfwInit() == GLFW_FALSE) {
			std::cout << "Failed to initialize GLFW" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
			});

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}
	}

	GLWindow::~GLWindow() {
		glfwTerminate();
	}

	void GLWindow::ProcessInput() {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}

	void GLWindow::SwapBuffers() {
		glfwSwapBuffers(window);
	}

	void GLWindow::PollEvents() {
		glfwPollEvents();
	}

	bool GLWindow::ShouldClose() {
		return glfwWindowShouldClose(window);
	}

	void GLWindow::EnableDepthBuffer() {
		glEnable(GL_DEPTH_TEST);
	}

	void GLWindow::ClearColor(float r, float g, float b, float a) {
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLWindow::ClearDepthBuffer() {
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	int GLWindow::GetWidth() {
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return width;
	}

	int GLWindow::GetHeight() {
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return height;
	}

	float GLWindow::GetAspectRatio()
	{
		return (float)GetWidth() / (float)GetHeight();
	}

}
