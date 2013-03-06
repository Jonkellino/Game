#pragma once

#include <array>
#include <vector>
#include "Chunk.h"

class Map
{
public:
	Map();
	~Map();

	void Render(const Vector2f& aCameraPosition);

//private:
//	std::vector< Chunk& > GetChunksInside( Vector2f aTopLeft, Vector2f aBottomRight );

public:
static struct CommonTileData
{
	Vector2f mySize;
} ourTileData;

static struct CommonChunkData
{
	Vector2i myNumberOfTiles;
	Vector2f mySize;
} ourChunkData;

private:
	static const unsigned int myNumberOfChunks = 4;
	std::array< std::array< Chunk, myNumberOfChunks >, myNumberOfChunks > myChunks;
};