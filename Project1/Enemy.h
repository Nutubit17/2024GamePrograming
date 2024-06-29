#pragma once
#include "IncludePack.h"

struct Enemy
{
	int addTime = 0;
	int difficulty = 0;
	vector<string> shape = {};

	BOOL LoadFromFile(ifstream& ifs);

};

vector<Enemy> LoadEnemiesFromFile(int difficulty);
