#pragma once

#include "Camera.h"
#include "Sprite.h"
#include "Box2D.h"

class b2Body;

class Player
{
public:
	Player(void);
	~Player(void);
	 
	void Init(b2World* aWorld);
	void Update( const float aDelta, Camera& aCamera );
	void FixedUpdate(const float aDelta);
	void Render();

private:
	void Movement( const float aDelta );

private:

	b2Body* myBody;
	Vector2f myPosition;
	Vector2f myPreviousPosition;
	Sprite mySprite;
};