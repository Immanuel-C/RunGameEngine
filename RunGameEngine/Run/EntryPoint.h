#include "Application.h"

extern Application* CreateApplication();

int main(int argc, char** argv)
{
	auto* app = CreateApplication();
	app->start();
	app->run();
	delete app;
}