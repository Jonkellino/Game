#pragma once

#include "Sprite.h"

class Player
{
public:
	Player(void);
	~Player(void);

private:
	Vector2f myPosition;
	Sprite mySprite;
};