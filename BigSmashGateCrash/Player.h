#pragma once

#include "Sprite.h"

class Player
{
public:
	Player(void);
	~Player(void);

private:
		void Update( const float aDelta );
	void Render();
private:
	Vector2f myPosition;
	Sprite mySprite;
};