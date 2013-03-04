#pragma once

#include "Map.h"
#include "Sprite"

class App
{
public:
	App(void);
	~App(void);

	bool Logic();//Should get DeltaTime

private:
	Map myMap;
};	Sprite myTest;
};