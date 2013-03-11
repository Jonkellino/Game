#pragma once

#include <array>
#include <vector>
#include "Sprite.h"

class b2World;
class b2Body;
class Camera;

class Chunk
{
public:
	Chunk(void);
	~Chunk(void);

	void Init(b2World* aWorld);

	void Render(const Camera& aCamera);

public: //ganna be refaktorerat någon dag
	static const unsigned int myNumberOfTilesHorizontal = 15;
	static const unsigned int myNumberOfTilesVertical = 20;
	Vector2i myIndex;

private:
	std::array< std::array< unsigned int, myNumberOfTilesHorizontal >, myNumberOfTilesVertical * 2 > myTiles;

	std::vector<b2Body*> myStaticObjects;
	Sprite mySprite;
	Sprite myStaticObjectSprite;
};