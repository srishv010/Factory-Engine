#include "Window.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			Window::Window(int width, int height, const char* title) : width(width), height(height), title(title) { }

			namespace OpenGL {

				GLWindow::GLWindow(int width, int height, const char* title) : Window(width, height, title) {
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

				void GLWindow::ClearColor(float r, float g, float b, float a) {
					glClearColor(r, g, b, a);
					glClear(GL_COLOR_BUFFER_BIT);
				}

			}
		}
	}
}
