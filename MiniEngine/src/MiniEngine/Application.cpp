#include "mepch.hpp"
#include "Application.hpp"

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

		while (true);
	}
}