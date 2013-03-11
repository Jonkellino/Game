#include "Chunk.h"
#include "Map.h"
#include "PhysicsWrapper.h"
#include "Camera.h"

Chunk::Chunk(void)
{
	mySprite.Load( "data/graphics/grass.png" );
	myStaticObjectSprite.Load( "data/graphics/mountains_3.png" );
	myStaticObjectSprite.Data().topLeft = Vector2i(1,1);
	myStaticObjectSprite.Data().size = Vector2i(90,64);
	myStaticObjectSprite.Data().depth = -1.f;
	myStaticObjectSprite.Data().hotspot.y = 0.65f;
}

Chunk::~Chunk(void)
{
}


void Chunk::Init(b2World* aWorld) 
{
	for(int i = 0; i < 5; ++i)
	{
		b2CircleShape* shape = new b2CircleShape();
		shape->m_radius =  50 / PTM_RATIO;

		b2Filter filter;

		b2FixtureDef fixtureDef;
		fixtureDef.shape = shape;
		fixtureDef.filter = filter;

		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.linearDamping = 1.5f;

		b2Body* body = aWorld->CreateBody( &bodyDef );
		body->CreateFixture( &fixtureDef );
		body->SetTransform( b2Vec2( ((rand()%myNumberOfTilesHorizontal)*100) / PTM_RATIO, ((rand()%myNumberOfTilesVertical)*50) / PTM_RATIO ), 0 );
		delete fixtureDef.shape;
		myStaticObjects.push_back(body);
	}
}


void Chunk::Render(const Camera& aCamera)
{
	int xOffset = 0;
	for( unsigned int yIndex = 0; yIndex < myNumberOfTilesVertical * 2; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfTilesHorizontal; xIndex++ )
		{
			mySprite.Data().pos.x = xIndex * 100 + xOffset;
			mySprite.Data().pos.y = yIndex * ( 50 / 2 );
			mySprite.Data().pos.x += 50 + ( static_cast<int>( Map::ourChunkData.mySize.x + 25 ) * myIndex.x );
			mySprite.Data().pos.y += 25 + ( static_cast<int>( Map::ourChunkData.mySize.y + 12.5 ) * myIndex.y );
			mySprite.Data().pos -= static_cast<Vector2i>(aCamera.GetPosition());
			mySprite.Render();
		}

		if( xOffset == 0 )
		{
			xOffset = 100 / 2;
		}
		else
		{
			xOffset = 0;
		}
	}

	for(auto& object : myStaticObjects)
	{
		const Vector2f worldPos = Vector2f(object->GetPosition().x, object->GetPosition().y) * PTM_RATIO;
		myStaticObjectSprite.Data().pos = static_cast<Vector2i>(worldPos - aCamera.GetPosition());
		myStaticObjectSprite.Render();
	}
}