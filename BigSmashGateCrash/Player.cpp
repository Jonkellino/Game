#include "Player.h"

Player::Player(void)
{
	myPosition = Vector2f( 300.0f, 200.0f );
	mySprite.Load( "data/graphics/player/player.png" );
}

Player::~Player(void)
{
}

void Player::Update( const float aDelta )
{
	mySprite.Data().pos = myPosition;
}

void Player::Render()
{
	mySprite.Render();
}