#include "Enemy.h"
#include "PhysicsWrapper.h"

Enemy::Enemy(void)
{

}

Enemy::~Enemy(void)
{
}

void Enemy::Init(b2World* aWorld)
{
	b2PolygonShape* shape = new b2PolygonShape();
	
	b2Vec2 vertices[8];
	float widthRadius = 50 / PTM_RATIO;
	float halfWidthRadius = widthRadius / 2;
	float heightRadius = widthRadius / 2;
	float halfHeightRadius = heightRadius / 2;
	vertices[0].Set( -widthRadius, -halfHeightRadius );
	vertices[1].Set( -halfWidthRadius, -heightRadius );
	vertices[2].Set( halfWidthRadius, -heightRadius );
	vertices[3].Set( widthRadius, -halfHeightRadius );
	vertices[4].Set( widthRadius, halfHeightRadius );
	vertices[5].Set( halfWidthRadius, heightRadius );
	vertices[6].Set( -halfWidthRadius, heightRadius );
	vertices[7].Set( -widthRadius, halfHeightRadius );
	shape->Set( vertices, 8 );

	b2Filter filter;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = shape;
	fixtureDef.filter = filter;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.linearDamping = 1.5f;

	myBody = aWorld->CreateBody( &bodyDef );
	myBody->CreateFixture( &fixtureDef );
	myBody->SetTransform( b2Vec2( 250 / PTM_RATIO, 250/ PTM_RATIO ), 0 );
	delete fixtureDef.shape;
}

void Enemy::Update(const float aDelta)
{
	mySprite.Data().angle = myRotationTarget;
}

void Enemy::FixedUpdate(const float aDelta)
{
	const Vector2f position = Vector2f(myBody->GetPosition().x, myBody->GetPosition().y);
	const Vector2f toTarget = myMoveTarget - position;

	const float arrivedRadius = 25.f;
	if(toTarget.LengthSquared() > arrivedRadius * arrivedRadius)
	{
		const float physUnitsPerSecond = 250.f * aDelta;
		const Vector2f toTargetNormal = toTarget.GetNormalized();
		b2Vec2 velocity(toTargetNormal.x, toTargetNormal.y);
		velocity *= physUnitsPerSecond;
		myBody->SetLinearVelocity(velocity);
	}
}

void Enemy::Render()
{
	mySprite.Render();
}

void Enemy::MoveTowards(const Vector2f aMoveTarget)
{
	myMoveTarget = aMoveTarget;
	myMoveTarget /= PTM_RATIO;
}

void Enemy::RotateTowards(float aRotation)
{
	myRotationTarget = aRotation;
}