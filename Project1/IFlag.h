#pragma once
#include "IncludePack.h"
class IFlag
{
private:
	TYPEENUM type;
public:
	bool IsPlayer();
	TYPEENUM GetType();
};
