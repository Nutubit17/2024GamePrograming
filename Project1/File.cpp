#include "IncludePack.h"

int main()
{
	std::ios_base::sync_with_stdio(false);


#pragma region	LoadFile

	ifstream loadFile("StartingCharacter.txt");

	vector<Character> characterInfo;
	Character character;

	//파일 불러오기
	while (!loadFile.eof())
	{
		character.LoadFromFile(loadFile);
		if (loadFile)
			characterInfo.push_back(character);
	}
	loadFile.close();

	// 불러온 캐릭터 정보
	for (const auto& character : characterInfo)
	{
		cout << character.name << " " << character.health << " " << character.attack << "\n";
	}

#pragma endregion



#pragma region LoadFileEnemy

	vector<Enemy> loadedEnemies = LoadEnemiesFromFile();

	SetConsoleOutputCP(CP_UTF8);

	// 적 정보 출력
	for (const Enemy& enemy : loadedEnemies)
	{
		cout << "Name: " << enemy.name << "\n";
		cout << "Health: " << enemy.health << "\n";
		cout << "Shape:\n";

		for (const string& line : enemy.shape)
		{
			cout << line << endl;
		}

		cout << "\n";
	}

#pragma endregion
}