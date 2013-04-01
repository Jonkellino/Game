#pragma once

#include <array>
#include "Inventable.h"

class Equipment
{
public:
	enum EQUIPSLOTS;

public:
	Equipment(void);
	~Equipment(void);

	void Render();

	void Use( EQUIPSLOTS aSlot );

public:
	enum EQUIPSLOTS
	{
		EQUIPSLOT_WEAPON,
		EQUIPSLOT_USEABLE,
		EQUIPSLOT_COUNT
	};

private:
	std::array< Inventable*, EQUIPSLOT_COUNT > mySlots;
	Inventable* myFist;
};