#include "Chunk.h"
#include "Map.h"

Chunk::Chunk(void)
{
	mySprite.Load( "data/graphics/grass.png" );
}

Chunk::~Chunk(void)
{
}

void Chunk::Render(const Vector2f& aCameraPosition)
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
			mySprite.Data().pos -= static_cast<Vector2i>(aCameraPosition);
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
}