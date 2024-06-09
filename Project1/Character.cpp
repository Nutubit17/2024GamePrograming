#include "Character.h"

void Character::SaveToFile(std::ofstream& ofs) const {
    ofs << name << " " << health << " " << attack << "\n";
}

void Character::LoadFromFile(std::ifstream& ifs) {
    ifs >> name >> health >> attack;
}
