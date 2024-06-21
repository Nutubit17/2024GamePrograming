#include "Character.h"

void Character::LoadFromFile(std::ifstream& ifs) {
    ifs >> name >> health >> attack;
}