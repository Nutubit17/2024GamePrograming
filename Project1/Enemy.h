#pragma once
#include <fstream>
#include <string>
using std::string;

struct Enemy
{
	string name;
	int health;

	void SaveToFile(std::ofstream& ofs) const;
	void LoadFromFile(std::ifstream& ifs);
};