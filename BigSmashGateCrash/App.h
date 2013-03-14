#pragma once

#include "PhysicsWrapper.h"
#include "Camera.h"
#include "Player.h"
#include "Text.h"
#include "Map.h"
#include "Enemy.h"


class App
{
public:
	App(void);
	~App(void);

	bool Logic(const float aDelta);

private: 
	void RenderFPS(const float aDelta);

	void Update( const float aDelta );
	void FixedUpdate( const float aDelta );
	void Render();

private:
	Text myFPSText;
	char* myFPSTextBuffer;

	PhysicsWrapper myPhysics;
	Enemy myEnemy; // TestTempLulz
	Camera myCamera;
	Player myPlayer;
	Map myMap; 
};