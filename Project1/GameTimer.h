#pragma once
#pragma once
#include "IncludePack.h"

struct GameTimer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
	long long totalPlayTime; // √  ¥‹¿ß
};

void StartGameTimer(GameTimer& gametime);
long long CalculatePlayTime(const GameTimer& gameTime);
void SaveGameTimer(GameTimer& gameTime);
GameTimer LoadGameTimer();