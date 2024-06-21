#pragma once

#include <iostream>
#include <io.h>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <algorithm>

#include <ostream>
#include <fstream>

#define _USE_MATH_DEFINES
#include <math.h>



using std::wcout;
using std::wcin;
using std::cout;
using std::cin;
using std::cerr;
using std::noskipws;
using std::endl;
using std::to_string;

using std::sin;
using std::vector;
using std::string;
using std::wstring;
using std::ofstream;
using std::ifstream;

#undef max
#undef min
using std::max;
using std::min;



enum class TYPEENUM
{
	Render = 0b001,
	Gauge = 0b010,
	Dialog = 0b011,
	ItemList = 0b100,
	SquareMap = 0b101,

	Player = 0b01000,
	Enemy = 0b10000
};

enum class SCENEENUM 
{
	Game,
	Description,
	Exit
};

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};

enum class INPUTTYPE 
{
	WAIT_ANY_KEY,
	WASD,
};

enum class CONSOLECONTROLTYPE 
{
	CLEAR,
	SCALE_INIT,
	POSITION_INIT,
	SCALE_MOVE,
	POSITION_MOVE,
};

struct ConsoleBounds
{
	COORD position;
	COORD scale;
};


#include "Defines.h"
#include "AdditionalMath.h"
#include "Console.h"
#include "Character.h"
#include "Enemy.h"