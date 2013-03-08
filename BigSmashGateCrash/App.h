#pragma once

#include "PhysicsWrapper.h"
#include "Camera.h"
#include "Player.h"
#include "Text.h"
#include "Map.h"

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

private:
	Text myFPSText;
	char* myFPSTextBuffer;

	PhysicsWrapper myPhysics;

	Camera myCamera;
	Player myPlayer;
	Map myMap;
};