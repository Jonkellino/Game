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

/*
std::vector< Chunk& > Map::GetChunksInside( Vector2f aTopLeft, Vector2f aBottomRight )
{
	std::vector< Chunk& > returnList;

	return returnList;
}
*/