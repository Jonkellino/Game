#pragma once

#include "Inventable.h"

class Handgun : public Inventable
{
public:
	Handgun(void);
	~Handgun(void);

	void Use();
};