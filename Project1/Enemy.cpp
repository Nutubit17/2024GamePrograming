#include "Enemy.h"

vector<Enemy> LoadEnemiesFromFile()
{
    vector<Enemy> enemies;
    ifstream ifs("enemy.txt");
    if (ifs.is_open())
    {
        while (ifs.peek() != EOF) // 파일 끝까지 읽기
        {
            Enemy enemy;
            ifs >> enemy.name >> enemy.health; // enemy의 이름과 체력을 파일에서 읽어와 저장
            ifs.ignore(); // 다음 데이터로 넘어갈때 발생하는 오류 방지 목적으로 새로운 줄 문자를 무시

            // shape 초기화
            enemy.shape.clear();
            for (int i = 0; i < 6; ++i) // 6*6
            {
                string line;
                getline(ifs, line); // 한 줄씩 읽어와 문자열로 저장
                enemy.shape.push_back(line);
            }
            enemies.push_back(enemy);
        }
        ifs.close();
    }
    else
    {
        cerr << "An error occurred when opening the file." << endl;
    }
    return enemies;
}
