#include "IncludePack.h"


void FileSystem()
{
	#pragma region	LoadCharacter
	vector<Character> characterInfo = LoadCharactersFromFile(); // 캐릭터들 불러와서 담아주기

	// 불러온 캐릭터 정보 출력
	for (const Character& character : characterInfo)
	{
		cout << character.name << " " << character.health << " " << character.attack << "\n";
	}

#pragma endregion

	#pragma region LoadFileEnemy

	vector<Enemy> loadedEnemies = LoadEnemiesFromFile(2); // 0, 1, 2로 난이도 선택해서 불러오기 0은 하, 1은 중, 2는 상

	SetConsoleOutputCP(CP_UTF8);

	// 적 정보 출력
	for (const Enemy& enemy : loadedEnemies)
	{
		cout << "Time: " << enemy.addTime << "\n";
		cout << "Difficulty: " << enemy.difficulty << "\n";
		cout << "Shape:\n";

		for (const string& line : enemy.shape)
		{
			cout << line << endl;
		}
		cout << "\n";
	}

#pragma endregion

	#pragma region HighScoreLoad

	// 최고 점수 로드
	vector<HighScore> highScores = LoadAllHighScore();

	// 새로운 점수 추가
	AddHighScore(highScores, 9);
	AddHighScore(highScores, 5);
	AddHighScore(highScores, 1);
	AddHighScore(highScores, 0);

	SaveAllHighScores(highScores);


	for (const HighScore& hs : highScores)
	{
		cout << hs.number << " " << hs.score << endl;
	}
#pragma endregion

	
}