#include "Application.hpp"

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include "Log.hpp"
#include<functional>
#include<memory>

namespace MiniEngine {

// create a forwarding call wrapper for Application::x
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

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
			m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		}
	}

	void Application::OnEvent(Event& e)
	{
		// if the event that goes through the dispatcher is a WindowCloseEvent, run Application::OnWindowClose;
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		ME_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}