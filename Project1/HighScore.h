#pragma once
#include "Includepack.h"
using namespace std;

struct HighScore
{
    int number = 0;
    int score = 0;

    void SaveToFile(ofstream& ofs) const;
};

vector<HighScore> LoadAllHighScore(const string& filename);
void SaveAllHighScores(const vector<HighScore>& highScores, const string& filename);
void AddHighScore(vector<HighScore>& highScores, int score);
bool CompareScores(const HighScore& a, const HighScore& b);
int GetHighestScore(const vector<HighScore>& highScores);