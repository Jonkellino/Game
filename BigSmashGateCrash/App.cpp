#include "App.h"
#include "SDL\SDL.h"
#include "Keyboard.h"

App::App(void)
{
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
	myPlayer.Update( aDelta, myCameraPosition );
	myMap.Render(myCameraPosition);
	myPlayer.Render();
	return false;
}