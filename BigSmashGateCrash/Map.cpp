#include "Map.h"
#include "Chunk.h"

Map::CommonTileData Map::ourTileData;
Map::CommonChunkData Map::ourChunkData;

Map::Map()
{
	ourTileData.mySize = Vector2f( 100.0f, 50.0f );
	ourChunkData.myNumberOfTiles.x = Chunk::myNumberOfTilesHorizontal;
	ourChunkData.myNumberOfTiles.y = Chunk::myNumberOfTilesVertical;
	ourChunkData.mySize = ourTileData.mySize * ourChunkData.myNumberOfTiles;
	for( unsigned int yIndex = 0; yIndex < myNumberOfChunks; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfChunks; xIndex++ )
		{
			myChunks[xIndex][yIndex].myIndex = Vector2i( xIndex, yIndex );
		}
	}
}

Map::~Map()
{
}

void Map::Render(const Vector2f& aCameraPosition)
{
	for( unsigned int yIndex = 0; yIndex < myNumberOfChunks; yIndex++ )
	{
		for( unsigned int xIndex = 0; xIndex < myNumberOfChunks; xIndex++ )
		{
			myChunks[xIndex][yIndex].Render(aCameraPosition);
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