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
	static const unsigned int myNumberOfTiles = 4;
	Vector2i myIndex;

private:
	std::array< std::array< unsigned int, myNumberOfTiles >, myNumberOfTiles * 2 > myTiles;
	
	Sprite myTest;
};