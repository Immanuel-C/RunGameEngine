#include "RunApplication.h"

#include "RunTime.h"

namespace Run {

	RunApplication::RunApplication()
	{

	}

	void RunApplication::Start()
	{
		window = std::make_unique<Window>(800, 600, "ERROR: DID NOT CREATE WINDOW IN Start()", nullptr, nullptr, false);
		std::cout << "ERROR: DID NOT CREATE WINDOW IN Start()";
	}

	void RunApplication::Update(float dt)
	{

	}

	void RunApplication::Loop()
	{
		double dt;

		while (!window->shouldClose())
		{
			dt = Time::calculateDt();
			Update(dt);
		}
	}

	void RunApplication::End()
	{

	}
}