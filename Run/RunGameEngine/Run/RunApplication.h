#pragma once

// Run
#include "Window.h"
#include "Core.h"

// std
#include <string>

namespace Run {
	class RUN_API RunApplication
	{
	public:
		RunApplication();

		virtual void Start();
		virtual void Update(float dt);
		virtual void End();

		void Loop();

		std::unique_ptr<Window> window;
	};
}