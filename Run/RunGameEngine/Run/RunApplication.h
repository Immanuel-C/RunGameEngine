#pragma once

#include "Window.h"
#include <string>

namespace Run {
	class RunApplication
	{
	public:
		RunApplication();

		virtual void Start();
		virtual void Update(float dt);
		virtual void End();

		void Loop();

		std::shared_ptr<Window> window;
	};
}