#include "App.h"
#include "SDL\SDL.h"

App::App(void)
{
	myPrevMSSinceInit = 0;
}

App::~App(void)
{
}

bool App::Logic(const float aDelta)
{
	myPlayer.Update( aDelta );
	myMap.Render();
	myPlayer.Render();
	return false;
}