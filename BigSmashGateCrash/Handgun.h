#pragma once

#include "Inventable.h"
#include "Equipable.h"

class Handgun : public Inventable, public Equipable
{
public:
	Handgun(void);
	~Handgun(void);
};