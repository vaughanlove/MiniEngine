#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"
#include "Window.hpp"
#include <memory>

namespace MiniEngine {
	class MINIENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}
