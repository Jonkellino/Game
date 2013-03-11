#pragma once

#define PTM_RATIO 32

#ifdef _DEBUG
#include "DebugDraw.h"
#endif
#include "Box2D.h"

//#include "PhysicsListener.h"
//#include "PhysicsBody.h"

class Camera;

class PhysicsWrapper
{
public:
	PhysicsWrapper(void);
	~PhysicsWrapper(void);

	void Step( const float aTimeStep );

#ifdef _DEBUG
	void SetDrawCamera(Camera* aCamera);
	void DrawDebug();
#endif

public:
	b2World* GetWorld(){ return myPhysicsWorld; }

private:
	b2World* myPhysicsWorld;
#ifdef _DEBUG
	DebugDraw myPhysicsDrawer;
#endif
	//PhysicsListener myPhysicsListener;

	static const int myVelocityIterations = 8;
	static const int myPositionIterations = 3;
};