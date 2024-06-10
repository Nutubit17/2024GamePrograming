#include "IncludePack.h"
#include<fcntl.h>

void FullScreen()
{
	ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);
}

void NoLabelScreen() 
{
	DWORD style = GetWindowLong(GetConsoleWindow(), GWL_STYLE);
	style &= ~WS_CAPTION & ~WS_HSCROLL & ~WS_VSCROLL;

	SetWindowLong(GetConsoleWindow(), GWL_STYLE, style);
}

void DisableEditMode() 
{
	HANDLE hInput;
	DWORD prev_mode;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
}


void FullScreenWithNoLabel()
{
	SetConsoleDisplayMode
	(GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,NULL);

	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

BOOL SetConsoleBounds(int x, int y, int width, int height, bool clear)
{
	BOOL result = MoveWindow(GetConsoleWindow(), x, y, width, height, clear);
	
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);

	COORD new_screen_buffer_size;

	new_screen_buffer_size.X = screenBufferInfo.srWindow.Right -
		screenBufferInfo.srWindow.Left + 1;
	new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom -
		screenBufferInfo.srWindow.Top + 1; 

	SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);

	return result;
}

void ShowConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOWDEFAULT);
}

void HideConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOWMINIMIZED);
}


void Gotoxy(int _x, int _y)
{
	//COORD Cur = { _x, _y };
	COORD Cur = { _x * 2, _y };
	// 콘솔 커서 위치를 딱 세팅
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)
		, Cur);
}

BOOL Gotoxytest(int _x, int _y)
{
	COORD Cur = { _x, _y };
	// 콘솔 커서 위치를 딱 세팅
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)
		, Cur);
}
COORD CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &Buf);
	return Buf.dwCursorPosition;
}

void SetCursorVis(bool _vis, DWORD _size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.dwSize = _size;  // 커서 굵기(1~100)
	curinfo.bVisible = _vis; // True: On, False: Off
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &curinfo);
}

void SetColor(int _textcolor, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
		, (_bgcolor << 4) | _textcolor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	int color = info.wAttributes & 0xf;
	return color;
}


void LockResize()
{
	HWND console = GetConsoleWindow();
	//NULL;
	// modern c++ 
	if (console != nullptr)
	{
		// 콘솔윈도우에 대한 핸들을 받아온거야.
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;// &~WS_HSCROLL;// &~WS_CAPTION;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	return COORD{ width, height };
}

COORD GetDesktopResolution()
{
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	return COORD{ (SHORT)desktop.right, (SHORT)desktop.bottom };
}



void FrameSync(unsigned int _framerate)
{
	clock_t oldtime, curtime;

	oldtime = clock();

	while (true)
	{
		curtime = clock();
		if ((curtime - oldtime) > 1000 / _framerate)
		{
			oldtime = curtime;
			break;
		}
	}
}

void SetMode(bool isUniCode)
{
	static int defaultMode = 0;

	if(defaultMode == 0 && !isUniCode) return;

	int previousMode
		= isUniCode? 
		_setmode(_fileno(stdout), _O_U16TEXT)
		: _setmode(_fileno(stdout), defaultMode);


	if (defaultMode == 0)
	{
		defaultMode = previousMode;
	}
}

void SetFontSize(int _size)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = _size;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

