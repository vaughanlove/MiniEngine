#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"

namespace MiniEngine {
	class MINIENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	Application* CreateApplication();

}
