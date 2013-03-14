#include "Enemy.h"
#include "PhysicsWrapper.h"
#include "Camera.h"

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

	mySprite.Load("data/graphics/enemy/orc.png");
	mySprite.Data().hotspot = Vector2f(0.5f, 1.0f);
	mySprite.Data().depth = -100.f;
	myRotationTarget = 0.f;
}

void Enemy::Update(const float aDelta)
{
	mySprite.Data().angle = myRotationTarget;
	if(myBody->GetLinearVelocity().x > 0)
	{
		mySprite.Data().flip = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		mySprite.Data().flip = SDL_FLIP_NONE;
	}
	
}

void Enemy::FixedUpdate(const float aDelta)
{
	const Vector2f position = Vector2f(myBody->GetPosition().x, myBody->GetPosition().y);
	const Vector2f toTarget = myMoveTarget - position;

	const float arrivedRadius = 25.f / PTM_RATIO;
	if(toTarget.LengthSquared() > arrivedRadius * arrivedRadius)
	{
		const float physUnitsPerSecond = 200.f * aDelta;
		const Vector2f toTargetNormal = toTarget.GetNormalized();
		b2Vec2 velocity(toTargetNormal.x, toTargetNormal.y);
		velocity *= physUnitsPerSecond;
		myBody->SetLinearVelocity(velocity);
	}

	mySprite.Data().pos = position * PTM_RATIO;
}

void Enemy::Render(const Camera& aCamera)
{
	Vector2f previousPos = mySprite.Data().pos;
	mySprite.Data().pos -= static_cast<Vector2i>(aCamera.GetPosition());
	mySprite.Render();
	mySprite.Data().pos = previousPos;
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