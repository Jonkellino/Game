#pragma once

#include <array>
#include <vector>
#include "Chunk.h"

class Map
{
public:
	Map();
	~Map( void );

	void Render();

//private:
//	std::vector< Chunk& > GetChunksInside( Vector2f aTopLeft, Vector2f aBottomRight );

private:
	static const unsigned int myNumberOfChunks = 1;
	std::array< std::array< Chunk, myNumberOfChunks >, myNumberOfChunks > myChunks;
};