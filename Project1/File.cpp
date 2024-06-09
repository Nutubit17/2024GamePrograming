#include <iostream>
#include <vector>
#include "Character.h"
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);

	vector<Character> characters = {
		{"Player1", 100, 20},
		{"Player2",  80, 30},
		{"Player4",  60, 40},
		{"Player5",  50, 50},
		{"Player6",  70, 35},
		{"Player7",  90, 25},
		{"Player8",  40, 60}
	};

#pragma region	WriteFile

	std::ofstream writeFile("StartingCharacter.text", std::ios_base::out);

	for (const auto& character : characters) 
	{
		character.SaveToFile(writeFile);
	}
	writeFile.close();

#pragma endregion

#pragma region	LoadFile

	ifstream loadFile("StartingCharacter.text");

	vector<Character> characterInfo;
	Character character;

	//���� �ҷ�����
	while (!loadFile.eof())
	{
		character.LoadFromFile(loadFile);
		if (loadFile)
			characterInfo.push_back(character);
	}
	loadFile.close();

	// �ҷ��� ĳ���� ����
	for (const auto& character : characterInfo)
	{
		cout << character.name << " " << character.health << " " << character.attack << "\n";
	}

#pragma endregion
}