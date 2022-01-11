#pragma once

#include "Core.h"

class Application
{
public:
	Application();
	virtual ~Application();

	virtual void start();
	virtual void run();
};

// define in client
Application* CreateApplication();

