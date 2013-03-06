#pragma once

#include "Player.h"
#include "Map.h"

class App
{
public:
	App(void);
	~App(void);

	bool Logic(const float aDelta);

private:
	Vector2f myCameraPosition;

	Player myPlayer;
	Map myMap;
};