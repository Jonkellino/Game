#pragma once

#include "Sprite.h"

class Player
{
public:
	Player(void);
	~Player(void);
	 
	void Update( const float aDelta, Vector2f& aCameraPosition );
	void Render();

private:
	void Movement(const float aDelta);
	Vector2f myPosition;
	Sprite mySprite;
};