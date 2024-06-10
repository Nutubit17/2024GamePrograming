#include "Enemy.h"

void Enemy::SaveToFile(std::ofstream& ofs) const
{
    ofs << name << " " << health << " " << attack << "\n";
}

void Enemy::LoadFromFile(std::ifstream& ifs) {
    ifs >> name >> health >> attack;
}
