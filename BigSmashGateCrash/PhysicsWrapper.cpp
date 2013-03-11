#include "PhysicsWrapper.h"
#include "Camera.h"

PhysicsWrapper::PhysicsWrapper(void)
{
	myPhysicsWorld = new b2World( b2Vec2( 0.0f, 0.0f ) );
#ifdef _DEBUG
	myPhysicsDrawer.AppendFlags( b2Draw::e_shapeBit );
	myPhysicsWorld->SetDebugDraw( &myPhysicsDrawer );
#endif
	//myPhysicsWorld->SetContactListener( &myPhysicsListener );
}

PhysicsWrapper::~PhysicsWrapper(void)
{
	delete myPhysicsWorld;
	myPhysicsWorld = 0;
}

void PhysicsWrapper::Step( const float aTimeStep )
{
	myPhysicsWorld->Step( aTimeStep, myVelocityIterations, myPositionIterations );
}

#ifdef _DEBUG
void PhysicsWrapper::SetDrawCamera(Camera* aCamera)
{
	myPhysicsDrawer.SetDrawCamera(aCamera);
}

void PhysicsWrapper::DrawDebug()
{
	myPhysicsWorld->DrawDebugData();
	myPhysicsDrawer.DrawDebugData();
}
#endif