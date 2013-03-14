#pragma once

#include "Sprite.h"

class Inventory
{
public:
	Inventory(void);
	~Inventory(void);

	void Update( const float aDelta );
	void Render();

private:
	Sprite myBackground;
};

