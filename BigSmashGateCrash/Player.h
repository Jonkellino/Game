#pragma once

#include "Camera.h"
#include "Sprite.h"

class Player
{
public:
	Player(void);
	~Player(void);
	 
	void Update( const float aDelta, Camera& aCamera );
	void Render();

private:
	void Movement( const float aDelta );

private:
	Vector2f myPosition;
	Vector2f myOffsetVector;
	Sprite mySprite;
};