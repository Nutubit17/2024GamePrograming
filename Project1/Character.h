#pragma once
#include "IncludePack.h"

struct Character
{
	string name = "";
	int health = 0;
	int attack = 0;

	void LoadFromFile(ifstream& ifs);
};