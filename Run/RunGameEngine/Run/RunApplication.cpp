#include "RunApplication.h"

RunApplication::RunApplication()
{

}

void RunApplication::Start()
{
	window = Window(800, 600, "Run Game Engine Example", nullptr, nullptr, false);
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
	while (!window.shouldClose())
	{
		currentTime = glfwGetTime();
		dt = currentTime - lastTime;
		Update(dt);
		counter++;
		if (dt >= 1.0f / 1000.0)
		{
			unsigned int FPS = 1.0 / dt * counter;
			std::cout << "Delta Time: " << dt << " FPS: " << FPS << "\n";
		}

		lastTime = currentTime;
	}
}

void RunApplication::End()
{

}
