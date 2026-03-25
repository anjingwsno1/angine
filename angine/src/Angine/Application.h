#pragma once

#include "Core.h"

namespace Angine {
	class ANGINE_API Application
	{	
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}