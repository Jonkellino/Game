#include "Map.h"

Map::CommonTileData Map::ourTileData;
Map::CommonChunkData Map::ourChunkData;

Map::Map()
{
	ourTileData.mySize = Vector2f( 100.0f, 50.0f );
	//ourChunkData.mySize = ourTileData.mySize * ned int yIndex = 0; yIndex < myNumberOfChunks; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfChunks; xIndex++ )
		{
			//myChunmyChunks[xIndex][yIndex].Render();myIndex = Vector2i( xIndex, yIndex );
		}
	}
}

Map::~Map(

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