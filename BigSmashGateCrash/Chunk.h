#pragma once

#include <array>
#include "Sprite.h"

class Chunk
{
public:
	Chunk(void);
	~Chunk(void);

	void Render(const Vector2f& aCameraPosition);

public: //ganna be refaktorerat någon dag
	static const unsigned int myNumberOfTilesHorizontal = 15;
	static const unsigned int myNumberOfTilesVertical = 20;
	Vector2i myIndex;

private:
	std::array< std::array< unsigned int, myNumberOfTilesHorizontal >, myNumberOfTilesVertical * 2 > myTiles;
	
	Sprite mySprite;
};