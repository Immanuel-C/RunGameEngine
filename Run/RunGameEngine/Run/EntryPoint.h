#include "RunApplication.h"

extern RunApplication* CreateApplication();


int main(int argc, char** argv)
{
	RunApplication* app = CreateApplication();
	app->Start();
	app->Loop();
	app->End();
	delete app;
}