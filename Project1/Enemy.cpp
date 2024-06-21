#include "Enemy.h"

vector<Enemy> LoadEnemiesFromFile()
{
    vector<Enemy> enemies;
    ifstream ifs("enemy.txt");
    if (ifs.is_open())
    {
        while (ifs.peek() != EOF) // ���� ������ �б�
        {
            Enemy enemy;
            ifs >> enemy.name >> enemy.health; // enemy�� �̸��� ü���� ���Ͽ��� �о�� ����
            ifs.ignore(); // ���� �����ͷ� �Ѿ�� �߻��ϴ� ���� ���� �������� ���ο� �� ���ڸ� ����

            // shape �ʱ�ȭ
            enemy.shape.clear();
            for (int i = 0; i < 6; ++i) // 6*6
            {
                string line;
                getline(ifs, line); // �� �پ� �о�� ���ڿ��� ����
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
