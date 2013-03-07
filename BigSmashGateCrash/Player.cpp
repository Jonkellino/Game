#include "Player.h"
#include "Keyboard.h"

Player::Player(void)
{
	myPosition = Vector2f( 300.0f, 200.0f );
	mySprite.Load( "data/graphics/player/player.png" );
}

Player::~Player(void)
{
}

void Player::Update( const float aDelta, Vector2f& aCameraPosition )
{
	Movement(aDelta);
	aCameraPosition = myPosition;
	mySprite.Data().pos = Vector2i(1680/2, 1024/2) + static_cast<Vector2i>(myOffsetVector);
	mySprite.Data().depth = -1.0f;
}

void Player::Render()
{
	mySprite.Render();
}

void Player::Movement(const float aDelta)
{
	Vector2f velocity;
	const float speed = 250;
	const float speedPerSecond = aDelta * speed;
	if(KeyboardInput->KeyDown(SDL_SCANCODE_D))
	{
		velocity.x += speedPerSecond;
	}
	if(KeyboardInput->KeyDown(SDL_SCANCODE_A))
	{
		velocity.x -= speedPerSecond;
	}
	if(KeyboardInput->KeyDown(SDL_SCANCODE_S))
	{
		velocity.y += speedPerSecond;
	}
	if(KeyboardInput->KeyDown(SDL_SCANCODE_W))
	{
		velocity.y -= speedPerSecond;
	}
	myPosition += velocity;
	const float clampRadius = 150.f;

	
	myOffsetVector += velocity;
	if(myOffsetVector.LengthSquared() > clampRadius*clampRadius)
	{	
		myOffsetVector.Normalize();
		myOffsetVector *= clampRadius-0.5f; // Dirty epsilon hack to keep it from inf-clamping.
	}
	else
	{
		Vector2f movement = myOffsetVector * aDelta;
		myPosition += movement;
		myOffsetVector -= movement;
	}
	
}