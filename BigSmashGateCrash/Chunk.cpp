#include "Chunk.h"

Chunk::Chunk(void)
{
	myTest.Load( "data/graphics/grass.png" );
	myTek::~Chunk(void)
{
}

void Chunk::Render()
{
	float xOffset = 0;
	for( unsigned int yIndex = 0; yIndex < myNumberOfTilesVertical * 2; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfTilesHorizontal; xIndex++ )
		{
			myTest.Data().pos.x = xIndex * 100 + xOffset;
			myTest.Data().pos.y = yIndex * ( 50 / 2 );
			myTest.Data().pos.x += 62.5 + ( ( 300 + 25 ) /*62.5 +*/ ( ( 300 + 25 ) * myIndex.x );
			myTest.Data().pos.y += /*125 +*/ndex.y );
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