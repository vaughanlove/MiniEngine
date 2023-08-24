#pragma once

#include "Core.hpp"

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
