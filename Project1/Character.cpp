#include "Character.h"

void Character::LoadFromFile(std::ifstream& ifs) {
    ifs >> name >> health >> attack;
}

vector<Character> LoadCharactersFromFile()
{
    vector<Character> characterInfo;
    ifstream loadFile("StartingCharacter.txt");

    if (loadFile.is_open()) {
        while (!loadFile.eof()) {
            Character character;
            character.LoadFromFile(loadFile);
            if (loadFile) {
                characterInfo.push_back(character);
            }
        }
        loadFile.close();
    }
    else {
        cerr << "An error occurred when opening the file." << endl;
    }

    return characterInfo;
}