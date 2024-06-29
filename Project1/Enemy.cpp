#include "Enemy.h"

BOOL Enemy::LoadFromFile(ifstream& ifs)
{
    return (bool)(ifs >> addTime >> difficulty);
}

vector<Enemy> LoadEnemiesFromFile(int difficulty)
{
    vector<Enemy> enemies;
    ifstream ifs("TextFile\\enemy.txt");

    if (!ifs.is_open()) return enemies;

    while (true)
    {
        Enemy enemy;
        string line;

        if (!enemy.LoadFromFile(ifs)) break;

        ifs.ignore(); //줄 문자(\n) 무시

        if (enemy.difficulty != difficulty)
        {
            for (int i = 0; i < 6; ++i)
                getline(ifs, line);
            continue;
        }

        for (int i = 0; i < 6; ++i)
        {
            getline(ifs, line);
            enemy.shape.push_back(line);
        }

        enemies.push_back(enemy);
    }
    ifs.close();
    return enemies;
}

