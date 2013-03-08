#include "App.h"
#include "SDL\SDL.h"
#include "Keyboard.h"

App::App(void)
{
	myFPSTextBuffer = new char[16];
	myFPSTextBuffer[0] = '\0';
	myFPSText.Load(myFPSTextBuffer, "FPSText");
	myFPSText.Data().pos = Vector2i(0,0);
	myFPSText.Data().hotspot = Vector2f(0,0);
	myFPSText.Data().depth = -1000.f;
}

App::~App(void)
{
	delete myFPSTextBuffer;
}

bool App::Logic(const float aDelta)
{
	KeyboardInput->Update();
	if(KeyboardInput->KeyDown(SDL_SCANCODE_ESCAPE))
	{
		return true;
	}
	RenderFPS(aDelta);
	myPlayer.Update( aDelta, myCamera );
	myMap.Render( myCamera );
	myPlayer.Render();
	return false;
}


void App::RenderFPS(const float aDelta) 
{
	myFPSTextBuffer[0] = '\0';
	itoa(static_cast<int>(1.f/aDelta), myFPSTextBuffer, 10);
	myFPSText.Load(myFPSTextBuffer, "FPSText");
	myFPSText.Render();
}