#include "HighScore.h"

void HighScore::SaveToFile(ofstream& ofs) const
{
    ofs << number << " " << score << endl;
}

vector<HighScore> LoadAllHighScore(const string& filename)
{
    vector<HighScore> highScores;
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        HighScore hs;
        while (ifs >> hs.number >> hs.score)
        {
            highScores.push_back(hs);
        }
        ifs.close();
    }
    return highScores;
}

void SaveAllHighScores(const vector<HighScore>& highScores, const string& filename)
{
    ofstream ofs(filename);
    if (ofs.is_open())
    {
        for (const auto& hs : highScores)
        {
            hs.SaveToFile(ofs);
        }
        ofs.close();
    }
}

int GetHighestScore(const vector<HighScore>& highScores)
{
    if (highScores.empty())
        return 0;

    return highScores.front().score;
}

void AddHighScore(vector<HighScore>& highScores, int score)
{
    int highestScore = GetHighestScore(highScores);
    if (score > highestScore)
    {
        HighScore newScore;
        newScore.score = score;
        highScores.push_back(newScore);
        sort(highScores.begin(), highScores.end(), CompareScores);

        // ��ȣ�� ������
        for (size_t i = 0; i < highScores.size(); ++i)
        {
            highScores[i].number = i + 1;
        }
    }
}

bool CompareScores(const HighScore& a, const HighScore& b)
{
    return a.score > b.score; // ���� ������ �տ� ������ ����
}