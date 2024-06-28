#pragma once
#include "Includepack.h"
struct Enemy
{
	int addTime = 0;
	int difficulty = 0;
	vector<string> shape = {};

};

vector<Enemy> LoadEnemiesFromFile(int difficulty);
