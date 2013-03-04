#pragma once

#include <array>
#include "Chunk.h"

class Map
{
public:
	Map( /*unsigned int aNumberOfChunks*/ );
	~Map( void );

private:
	s	void Render();

private:
	static const unsigned int myNumberOfChunks = 5;
	std::array< std::array< Chunk, myNumberOfChunks >, myNumberOfChunks > myChunks;
};