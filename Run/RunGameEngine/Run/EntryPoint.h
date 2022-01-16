#include "RunApplication.h"

extern Run::RunApplication* CreateApplication();


int main(int argc, char** argv)
{
	Run::RunApplication* app = CreateApplication();
	app->Start();
	app->Loop();
	app->End();
	delete app;
}