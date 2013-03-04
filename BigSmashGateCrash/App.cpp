#include "App.h"

App::App(void)
{
	myTest.Load( "data/graphics/grass.png" );
	myTest.Data().pos.x = 200;
	myTest.Data().pos.y = 200;
}

App::~App(void)
{
}

bool App::Logic()
{
	myTest.Render();
	return false;
}