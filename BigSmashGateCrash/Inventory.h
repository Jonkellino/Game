#pragma once

#include "Sprite.h"
#include "Inventable.h"
#include "Equipment.h"
#include <array>

class Inventory
{
	friend class Player;
public:
	Inventory(void);
	~Inventory(void);

	void Update( const float aDelta );
	void Render();

	bool AddItem( Inventable* anItem );

private:
	Equipment* myEquipment;
	Sprite myBackground;

	static const unsigned char myNumberOfItemSlots = 8;
	std::array< Inventable*, myNumberOfItemSlots > mySlots;
};