#pragma once


class Canvas 
{
public:
	Canvas() :
		width(0),
		height(0),
		previousX(0),
		previousY(0),
		charTex(vector<vector<wchar_t>>()),
		isTransparent(true),
		bkColor(COLOR::BLACK),
		textColor(COLOR::WHITE)
	{

	}


protected:
	COLOR bkColor;
	COLOR textColor;
	int previousX, previousY;
	int width, height;
	vector<vector<wchar_t>> charTex;
	bool isTransparent;

public:
	void SetRenderColor(COLOR _textColor, COLOR _bkColor);
	void SetRectangle(int _width, int _height);
	void SetCircle(int _width, int _height);
	void ClearTex();
	void SetTransparent(bool isTransparent);
	void Render(int _x, int _y);
};
