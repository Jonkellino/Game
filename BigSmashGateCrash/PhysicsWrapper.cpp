#include "PhysicsWrapper.h"

PhysicsWrapper::PhysicsWrapper(void)
{
	//myPhysicsWorld = new b2World( b2Vec2( 0.0f, 0.0f ) );
	/*
	myPhysicsDrawer.AppendFlags( b2Draw::e_shapeBit );
#ifdef _DEBUG
	myPhysicsWorld->SetDebugDraw( &myPhysicsDrawer );
#endif
	myPhysicsWorld->SetContactListener( &myPhysicsListener );
	*/
}

PhysicsWrapper::~PhysicsWrapper(void)
{
}

void PhysicsWrapper::Step( const float aTimeStep )
{
	//myPhysicsWorld->Step( aTimeStep, myVelocityIterations, myPositionIterations );
}

void PhysicsWrapper::DrawDebug()
{
	/*
	myPhysicsDrawer.SetCameraPos( GraphicsEngine::GetInstance()->GetCameraPosition() );
	myPhysicsWorld->DrawDebugData();
	myPhysicsDrawer.DrawDebugData();
	*/
}