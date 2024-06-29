#include "Character.h"

BOOL Character::LoadFromFile(std::ifstream& ifs) {
	return (bool)(ifs >> name >> health >> attack);
}

vector<Character> LoadCharactersFromFile()
{
	vector<Character> characterInfo;
	ifstream loadFile("TextFile\\StartingCharacter.txt");

	if (!loadFile.is_open()) return characterInfo;

	while (true)
	{
		Character character;
		if (!character.LoadFromFile(loadFile)) break;

		characterInfo.push_back(character);
	}

	loadFile.close();

	return characterInfo;
}