#pragma once

#include <array>
#include "Sprite.h"

class Chunk
{
public:
	Chunk(void);
	~Chunk(void);

	void Render();

public: //ganna be refaktorerat någon dag
	Vector2i myIndexte:
	static const unsigned int myNumberOfTilesHorizontal = 3;
	static const unsigned1;
	static const unsigned int myNumberOfTilesVertical = 1std::array< unsigned int, myNumberOfTilesHorizontal >, myNumberOfTilesVertical * 2 > myTiles;
	
	Sprite myTest;
};