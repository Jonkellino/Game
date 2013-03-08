#pragma once

#include <array>
#include <vector>
#include "Camera.h"
#include "Chunk.h"

class Map
{
public:
	Map();
	~Map();

	void Render( const Camera& aCamera );

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
	static const unsigned int myNumberOfChunks = 1;
	std::array< std::array< Chunk, myNumberOfChunks >, myNumberOfChunks > myChunks;
};