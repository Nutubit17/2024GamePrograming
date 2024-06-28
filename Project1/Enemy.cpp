#include "Enemy.h"

vector<Enemy> LoadEnemiesFromFile(int difficulty)
{
    vector<Enemy> enemies;
    ifstream ifs("enemy.txt");
    if (ifs.is_open())
    {
        while (ifs.peek() != EOF) // ���� ������ �б�
        {
            Enemy enemy;
            ifs >> enemy.addTime >> enemy.difficulty; // enemy�� �̸�, ü��, ���̵��� ���Ͽ��� �о�� ����
            ifs.ignore(); // ���� �����ͷ� �Ѿ�� �߻��ϴ� ���� ���� �������� ���ο� �� ���ڸ� ����

            // ���õ� ���̵��� ��ġ���� �ʴ� ���� ����� �ǳʶ�
            if (enemy.difficulty != difficulty)
            {
                for (int i = 0; i < 6; ++i) // ��� ũ��� 6*6���� ����
                {
                    string line;
                    getline(ifs, line);
                }
                continue;
            }

            // shape �ʱ�ȭ �� ��� �б�
            enemy.shape.clear();
            for (int i = 0; i < 6; ++i) // ��� ũ��� 6*6���� ����
            {
                string line;
                getline(ifs, line); // �� �پ� �о�� ���ڿ��� ����
                enemy.shape.push_back(line);
            }

            // ���õ� ���̵��� ��ġ�ϴ� ���� �߰�
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
