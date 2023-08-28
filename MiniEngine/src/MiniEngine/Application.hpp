#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Window.hpp"

namespace MiniEngine {
	class MINIENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& e);
		
		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}
