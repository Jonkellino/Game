#pragma once

#include <array>

class Chunk
{
public:
	Chunk(void);
	~Chunk(void);

private:
	static const unsigned int myNumberOfTilesHorizontal = 3;
	static const unsigned int myNumberOfTilesVertical = 5;
	std::array< std::array< unsigned int, myNumberOfTilesHorizontal >, myNumberOfTilesVertical > myTiles;
};