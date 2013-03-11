#include "Player.h"
#include "Keyboard.h"
#include "PhysicsWrapper.h"
#include "Engine.h"

Player::Player(void)
{
	myPosition = Vector2f( 300.0f, 200.0f );
	mySprite.Load( "data/graphics/player/player.png" );
}

Player::~Player(void)
{
}

void Player::Init(b2World* aWorld) 
{
	b2CircleShape* shape = new b2CircleShape();
	shape->m_radius =  100 / 2.0f / PTM_RATIO;

	b2Filter filter;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = shape;
	fixtureDef.filter = filter;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.linearDamping = 1.5f;

	myBody = aWorld->CreateBody( &bodyDef );
	myBody->CreateFixture( &fixtureDef );
	myBody->SetTransform( b2Vec2( 100 / PTM_RATIO, 100 / PTM_RATIO ), 0 );
	delete fixtureDef.shape;
}

void Player::Update( const float aDelta, Camera& aCamera )
{
	const Vector2i screenSize = Engine::GetInstance()->GetWindowSize();
	aCamera.SetPosition( myPosition ); 
	mySprite.Data().pos = screenSize / 2;
	mySprite.Data().depth = -1.0f;
}

void Player::FixedUpdate(const float aDelta)
{
	Movement(aDelta);
}

void Player::Render()
{
	mySprite.Render();
}

void Player::Movement( const float aDelta )
{

	const float physUnitsPerSecond = 250.f * aDelta;
	Vector2f velocity;
	
	if(KeyboardInput->KeyDown(SDL_SCANCODE_D))
	{
		velocity.x += physUnitsPerSecond;
	}
	if(KeyboardInput->KeyDown(SDL_SCANCODE_A))
	{
		velocity.x -= physUnitsPerSecond;
	}
	if(KeyboardInput->KeyDown(SDL_SCANCODE_S))
	{
		velocity.y += physUnitsPerSecond;
	}
	if(KeyboardInput->KeyDown(SDL_SCANCODE_W))
	{
		velocity.y -= physUnitsPerSecond;
	}
	myBody->ApplyForceToCenter(b2Vec2(velocity.x, velocity.y));

	const float clampRadius = 150.f;
	myOffsetVector += (myPosition - myPreviousPosition );
	if(myOffsetVector.LengthSquared() > clampRadius*clampRadius)
	{	
		myOffsetVector.Normalize();
		myOffsetVector *= clampRadius-0.5f; // Dirty epsilon hack to keep it from inf-clamping.
	}
	myOffsetVector *= 0.95f;
	const b2Vec2& physPos = myBody->GetPosition();
	Vector2f worldPos(physPos.x * PTM_RATIO, physPos.y * PTM_RATIO);
	myPreviousPosition = myPosition;
	myPosition = worldPos;

	
}