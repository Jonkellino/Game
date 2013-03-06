#include "App.h"
#include "SDL\SDL.h"
#include "Keyboard.h"

App::App(void)
{
	myPrevMSSinceInit = 0;
}

App::~App(void)
{
}

bool App::Logic(const float aDelta)
{
	KeyboardInput->Update();
	if(KeyboardInput->KeyDown(SDL_SCANCODE_ESCAPE))
	{
		return true;
	}
	myPlayer.Update( aDelta );
	myMap.Render();
	myPlayer.Render();
	return false;
}