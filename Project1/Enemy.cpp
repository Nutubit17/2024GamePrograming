#include "Enemy.h"

vector<Enemy> LoadEnemiesFromFile(int difficulty)
{
    vector<Enemy> enemies;
    ifstream ifs("enemy.txt");
    if (ifs.is_open())
    {
        while (ifs.peek() != EOF) // 파일 끝까지 읽기
        {
            Enemy enemy;
            ifs >> enemy.addTime >> enemy.difficulty; // enemy의 이름, 체력, 난이도를 파일에서 읽어와 저장
            ifs.ignore(); // 다음 데이터로 넘어갈때 발생하는 오류 방지 목적으로 새로운 줄 문자를 무시

            // 선택된 난이도와 일치하지 않는 적은 모양을 건너뜀
            if (enemy.difficulty != difficulty)
            {
                for (int i = 0; i < 6; ++i) // 모양 크기는 6*6으로 고정
                {
                    string line;
                    getline(ifs, line);
                }
                continue;
            }

            // shape 초기화 및 모양 읽기
            enemy.shape.clear();
            for (int i = 0; i < 6; ++i) // 모양 크기는 6*6으로 고정
            {
                string line;
                getline(ifs, line); // 한 줄씩 읽어와 문자열로 저장
                enemy.shape.push_back(line);
            }

            // 선택된 난이도와 일치하는 적만 추가
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
