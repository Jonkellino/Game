#include "Chunk.h"
#include "Map.h"

Chunk::Chunk(void)
{
	myTest.Load( "data/graphics/grass.png" );
}

Chunk::~Chunk(void)
{
}

void Chunk::Render()
{
	float xOffset = 0;
	for( unsigned int yIndex = 0; yIndex < myNumberOfTiles * 2; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfTiles; xIndex++ )
		{
			myTest.Data().pos.x = xIndex * 100 + xOffset;
			myTest.Data().pos.y = yIndex * ( 50 / 2 );
			myTest.Data().pos.x += 50 + ( ( Map::ourChunkData.mySize.x + 25 ) * myIndex.x );
			myTest.Data().pos.y += 25 + ( ( Map::ourChunkData.mySize.y + 12.5 ) * myIndex.y );
			myTest.Render();
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