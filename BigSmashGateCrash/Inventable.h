#pragma once

#include "Sprite.h"

class Inventable
{
public:
	Inventable(){};
	virtual ~Inventable(){};

public:
	enum ITEMTYPE
	{
		ITEMTYPE_NORMAL,
		ITEMTYPE_WEAPON,
		ITEMTYPE_USEABLE,
		ITEMTYPE_COUNT,
	};

	Sprite myInventoryIcon;
};