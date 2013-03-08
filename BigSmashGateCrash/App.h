#pragma once

#include "Camera.h"
#include "Player.h"
#include "Text.h"
#include "Map.h"

class App
{
public:
	App(void);
	~App(void);

	bool Logic(const float aDelta);

private:
	void RenderFPS(const float aDelta);

private:
	Text myFPSText;
	char* myFPSTextBuffer;

	Camera myCamera;
	Player myPlayer;
	Map myMap;
};