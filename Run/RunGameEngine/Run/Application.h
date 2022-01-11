#pragma once

class Application
{
public:
	Application();
	virtual ~Application();

	virtual void start();
	virtual void run();
};
