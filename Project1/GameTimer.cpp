#include "GameTimer.h"

void StartGameTimer(GameTimer& gametime)
{
	gametime.startTime = std::chrono::high_resolution_clock::now();
}

long long CalculatePlayTime(const GameTimer& gameTime)
{
	auto endTime = std::chrono::high_resolution_clock::now(); // ÀÚ·áÇü =  chrono::time_point<chrono::high_resolution_clock>
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(endTime - gameTime.startTime);
	return gameTime.totalPlayTime + static_cast<long long>(elapsed.count());
}

void SaveGameTimer(GameTimer& gameTime)
{
	gameTime.totalPlayTime = CalculatePlayTime(gameTime);

	ofstream outFile("TextFile\\gametime.txt");
	if (outFile.is_open())
	{
		outFile << gameTime.totalPlayTime;
		outFile.close();
	}
}

GameTimer LoadGameTimer()
{
	GameTimer gameTime;
	ifstream inFile("TextFile\\gametime.txt");
	if (inFile.is_open())
	{
		inFile >> gameTime.totalPlayTime;
		inFile.close();
	}
	else
		gameTime.totalPlayTime = 0;

	return gameTime;
}