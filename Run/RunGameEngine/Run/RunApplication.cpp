#include "RunApplication.h"

//#define DEBUG 

namespace Run {

	RunApplication::RunApplication()
	{

	}

	void RunApplication::Start()
	{
		window = std::make_shared<Window>(800, 600, "ERROR: DID NOT SET WINDOW IN START()", nullptr, nullptr, false);
	}

	void RunApplication::Update(float dt)
	{

	}

	void RunApplication::Loop()
	{

		float currentTime = 0.0f;
		float dt;
		float lastTime = 0.0f;
		unsigned int counter = 0;
		while (!window->shouldClose())
		{
			currentTime = glfwGetTime();
			dt = currentTime - lastTime;
			Update(dt);
#ifdef DEBUG  
			unsigned int FPS = 1.0 / dt;
			std::cout << "FPS: " << FPS << " Delta Time: " << dt << "\n";
#endif // DEBUG 
			lastTime = currentTime;
		}
	}

	void RunApplication::End()
	{

	}
}