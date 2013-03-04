#include "Map.h"

Map::Map( /*unsigned int aNumberOfChunks*/ )
{
	for( unsigned int yIndex = 0; yIndex < myNumberOfChunks; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfChunks; xIndex++ )
		{
			//myChunmyChunks[xIndex][yIndex].myIndex = Vector2i( xIndex, yIndex );
		}
	}
}

Map::~Map( void )
{
}

void Map::Render({
	for( unsigned int yIndex = 0; yIndex < myNumberOfChunks; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfChunks; xIndex++ )
		{
			//myChunmyChunks[xIndex][yIndex].Render();
		}
	}
}