#include "IncludePack.h"

int main()
{
	std::ios_base::sync_with_stdio(false);


#pragma region	LoadCharacter
	vector<Character> characterInfo = LoadCharactersFromFile(); // ĳ���͵� �ҷ��ͼ� ����ֱ�

	// �ҷ��� ĳ���� ���� ���
	for (const Character& character : characterInfo)
	{
		cout << character.name << " " << character.health << " " << character.attack << "\n";
	}

#pragma endregion

#pragma region LoadFileEnemy

	vector<Enemy> loadedEnemies = LoadEnemiesFromFile(2); // 0, 1, 2�� ���̵� �����ؼ� �ҷ����� 0�� ��, 1�� ��, 2�� ��

	SetConsoleOutputCP(CP_UTF8);

	// �� ���� ���
	for (const Enemy& enemy : loadedEnemies)
	{
		cout << "Name: " << enemy.name << "\n";
		cout << "Health: " << enemy.health << "\n";
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

	// �ְ� ���� �ε�
	vector<HighScore> highScores = LoadAllHighScore();

	// ���ο� ���� �߰�
	AddHighScore(highScores, 9);
	AddHighScore(highScores, 5);
	AddHighScore(highScores, 1);
	AddHighScore(highScores, 0);

	SaveAllHighScores(highScores);


	for (const auto& hs : highScores)
	{
		cout << hs.number << " " << hs.score << endl;
	}
#pragma endregion



}