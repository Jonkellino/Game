#pragma once

#include <array>
#include "Inventable.h"

class Equipment
{
public:
	Equipment(void);
	~Equipment(void);

public:
	enum EQUIPSLOTS
	{
		EQUIPSLOT_WEAPON,
		EQUIPSLOT_USEABLE,
		EQUIPSLOT_COUNT
	};

private:
	std::array< Inventable*, EQUIPSLOT_COUNT > mySlots;
};