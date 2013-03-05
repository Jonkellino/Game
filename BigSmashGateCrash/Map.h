#pragma once

#include <array>
#include <vector>
#include "Chunk.h"

class Map
{
public:
	Map();
	~Map( void );

Render();

//private:
//	std::vector< Chunk& > GetChunksInside( Vector2f aTopLeft, Vector2f aBottomRight );

private:
	static cublic:
static struct CommonTileData
{
	Vector2f mySize;
} ourTileData;

static struct CommonChunkData
{
	Vector2f mySize;
	unsigned int myNumberOfTilesHorizontal;
	unsigned int myNumberOfTilesVertical;
} ourChunkDataatic const unsigned int myNumberOfChunks = 1;
	std::array< std::array< Chunk, myNumberOfChunks >, myNumberOfChunks > myChunks;
};