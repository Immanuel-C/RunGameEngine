#pragma once

#include "Window.h"

class RunApplication
{
public:
	RunApplication();

	virtual void Start();
	virtual void Update(float dt);
	virtual void End();

	void Loop();

	Window window;
};
