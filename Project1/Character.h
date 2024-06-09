#pragma once
#include <fstream>
#include <string>
using std::string;

struct Character 
{
	string name;
	int health;
	int attack;

	void SaveToFile(std::ofstream& ofs) const;
	void LoadFromFile(std::ifstream& ifs);
};