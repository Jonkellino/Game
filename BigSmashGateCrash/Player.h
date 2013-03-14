#pragma once

#include <array>
#include <functional>
#include "Camera.h"
#include "Sprite.h"
#include "Box2D.h"
#include "Equipment.h"
#include "Inventory.h"

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
	enum PLAYERSTATES
	{
		PLAYERSTATE_PLAYING,
		PLAYERSTATE_INVENTORY,
		PLAYERSTATE_COUNT,
	} myState;

private:
	b2Body* myBody;
	Vector2f myPosition;
	Sprite mySprite;
	Equipment myEquipment;
	Inventory myInventory;
};