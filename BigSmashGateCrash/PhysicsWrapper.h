#pragma once

#include "Box2D.h"
//#include "DebugDraw.h"
//#include "PhysicsListener.h"
//#include "PhysicsBody.h"
//#include "LuaPlus.h"

class PhysicsWrapper
{
public:
	PhysicsWrapper(void);
	~PhysicsWrapper(void);

	void Step( const float aTimeStep );
	void DrawDebug();

	/*
	LuaPlus::LuaObject CreateShapeBox( float aWidth, float aHeight );
	LuaPlus::LuaObject CreateShapeCircle( float aRadius );

	LuaPlus::LuaObject CreateFilter();
	LuaPlus::LuaObject CreateFixture( LuaPlus::LuaObject aShape );
	LuaPlus::LuaObject CreateBodyDef();

	LuaPlus::LuaObject CreateBody( LuaPlus::LuaObject aFilter, LuaPlus::LuaObject aFixture, LuaPlus::LuaObject aBodyDef, LuaPlus::LuaObject anObject );
	void DestroyBody( LuaPlus::LuaObject aBody );
	*/

private:
	b2World* myPhysicsWorld;
	//DebugDraw myPhysicsDrawer;
	//PhysicsListener myPhysicsListener;

	static const int myVelocityIterations = 8;
	static const int myPositionIterations = 3;
};