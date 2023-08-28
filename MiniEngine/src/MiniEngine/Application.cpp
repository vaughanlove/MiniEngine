#include "Application.hpp"

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace MiniEngine {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() 
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}