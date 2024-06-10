#include "IncludePack.h"
#include "Unit.h"


void Canvas::SetRenderColor(COLOR _textColor, COLOR _bkColor)
{
	textColor = _textColor;
	bkColor = _bkColor;
}



void Canvas::ClearTex()
{
	for (int i = 0; i < charTex.size(); ++i) 
	{
		charTex[i].clear();
	}
	charTex.clear();

	width = 0;
	height = 0;
	previousX = 0;
	previousY = 0;
}


void Canvas::SetRectangle(int _width, int _height)
{
	ClearTex();

	width = _width;
	height = _height;
	
	for (int i = 0; i < width; ++i) 
	{
		charTex.push_back(vector<wchar_t>());
		for (int j = 0; j < height; ++j) 
		{
			charTex[i].push_back(L' ');
		}
	}

}



void Canvas::SetCircle(int _width, int _height)
{
	width = _width;
	height = _height;

	for (int i = 0; i < width; ++i)
	{
		charTex.push_back(vector<wchar_t>());
		for (int j = 0; j < height; ++j)
		{
			float x = ((float)i / (width-1) * 2 - 1);
			float y = ((float)j / (height-1) * 2 - 1);
			float distance = x * x + y * y;

			if (distance <= 1)
				charTex[i].push_back(L' ');
			else
				charTex[i].push_back((wchar_t)0);
		}
	}
}

void Canvas::SetTransparent(bool isTransparent)
{
	this->isTransparent = isTransparent;
}


void Canvas::Render(int _x, int _y)
{
	previousX = _x;
	previousY = _y;


	COORD consoleResol = GetConsoleResolution();
	int minX, maxX;
	int minY, maxY;


	minX = max(0, _x);
	maxX = min((int)consoleResol.X, _x + width);
	minY = max(0, _y);
	maxY = min((int)consoleResol.Y, _y + height);


	for (int i = minX; i < maxX; ++i) 
	{
		for (int j = minY; j < maxY; ++j) 
		{
			char currentChar = charTex[i - _x][j - _y];

			// 여기서 렌더링을 해줍니다. 
			if (currentChar)
			{
			}
			else if (!isTransparent)
			{
			}
		}
	}
}


