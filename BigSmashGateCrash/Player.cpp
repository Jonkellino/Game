#include "Player.h"
#include "Keyboard.h"
#include "PhysicsWrapper.h"
#include "Engine.h"

Player::Player(void)
{
	myState = PLAYERSTATE_PLAYING;
	myPosition = Vector2f( 300.0f, 200.0f );
	mySprite.Load( "data/graphics/player/player.png" );
}

Player::~Player(void)
{
}

void Player::Init(b2World* aWorld) 
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

void Player::Update( const float aDelta, Camera& aCamera )
{
	if( KeyboardInput->KeyPressed( SDL_SCANCODE_I ) )
	{
		if( myState == PLAYERSTATE_PLAYING )
		{
			myState = PLAYERSTATE_INVENTORY;
		}
		else if( myState == PLAYERSTATE_INVENTORY )
		{
			myState = PLAYERSTATE_PLAYING;
		}
	}

	if( myState == PLAYERSTATE_PLAYING )
	{
		const Vector2i screenSize = Engine::GetInstance()->GetWindowSize();
		aCamera.SetPosition( myPosition - screenSize / 2); 
		mySprite.Data().pos = screenSize / 2;
		mySprite.Data().depth = -1.0f;
	}
	else if( myState == PLAYERSTATE_INVENTORY )
	{
	}
}

void Player::FixedUpdate(const float aDelta)
{
	if( myState == PLAYERSTATE_PLAYING )
	{
		Movement(aDelta);
	}
	else if( myState == PLAYERSTATE_INVENTORY )
	{
		myBody->SetLinearVelocity( b2Vec2( 0, 0 ) );
	}
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
	myBody->SetLinearVelocity( b2Vec2( velocity.x, velocity.y ) );

	const float clampRadius = 150.f;
	myOffsetVector += (myPosition - myPreviousPosition );
	if(myOffsetVector.LengthSquared() > clampRadius*clampRadius)
	{	
		myOffsetVector.Normalize();
		myOffsetVector *= clampRadius-0.5f; // Dirty epsilon hack to keep it from inf-clamping.
	}
	myOffsetVector *= 0.95f;
	const b2Vec2& physPos = myBody->GetPosition();
	Vector2f worldPos(physPos.x * PTM_RATIO, ( physPos.y * PTM_RATIO ) - 40);
	myPreviousPosition = myPosition;
	myPosition = worldPos;
}