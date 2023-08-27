#include "Application.hpp"

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace MiniEngine {
	Application::Application() {
		
	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		ME_TRACE(e);


		glfwInit();
		GLFWwindow* window = glfwCreateWindow(1280, 720, "MiniEngine Window", NULL, NULL);
		glfwMakeContextCurrent(window); //this is the window OpenGL will be applied to

		while (!glfwWindowShouldClose(window)) {
			glfwSwapBuffers(window);
			glfwWaitEvents();
		}

	}
}