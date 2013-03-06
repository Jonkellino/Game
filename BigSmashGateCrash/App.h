#pragma once

#include "Map.h"

class App
{
public:
	App(void);
	~App(void);

	bool Logic(const float aDelta);

private:
	int myPrevMSSinceInit;
	Map myMap;
};