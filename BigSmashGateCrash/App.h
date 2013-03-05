#pragma once

#include "Map.h"

class App
{
public:
	App(void);
	~App(void);

	bool Logic();//Should get DeltaTime

private:
	Map myMap;
};