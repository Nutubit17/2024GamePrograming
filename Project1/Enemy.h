#pragma once
#include "Includepack.h"
struct Enemy
{
	string name = "";
	int health = 0;
	int difficulty = 0;
	vector<string> shape = {};

};

vector<Enemy> LoadEnemiesFromFile(int difficulty);
