#include "IncludePack.h"
#include "Logic.h"

Core* Core::m_pInst = nullptr;

void ConsoleInit()
{
	LockResize();
	NoLabelScreen();
	DisableEditMode();
	SetCursorVis(false, 1);
}

void Core::Init()
{
	SetMode(true);
}

void Core::Run()
{
	RenderQueue * renderQueue = new RenderQueue();
	
	AttentionTextRender();
	DescriptionRender();
}

void Core::Update(TYPEENUM type, int count)
{

}

COORD Core::Input(INPUTTYPE inputType)
{
	switch (inputType)
	{
	case INPUTTYPE::WAIT_ANY_KEY:
		while (!_kbhit()) {}
		break;
	case INPUTTYPE::WASD:
		// 여기서 상하좌우 이동 구현해주세요. 
		break;
	}
	return COORD();
}

void Core::ConsoleControl(CONSOLECONTROLTYPE controlType, COORD inp, float speed)
{
	static bool isPositionInited, isScaleInited;
	static ConsoleBounds previousBounds;

	switch (controlType)
	{
	case CONSOLECONTROLTYPE::CLEAR:
		system("cls");
	break;
	case CONSOLECONTROLTYPE::SCALE_INIT:
		 previousBounds.scale = inp;
		isScaleInited = true;
	break;
	case CONSOLECONTROLTYPE::POSITION_INIT:
		previousBounds.position = inp;
		isPositionInited = true;
	break;
	case CONSOLECONTROLTYPE::SCALE_MOVE:
	{
		if (!isScaleInited) return;
		float percent = 0.0f;

		while (percent <= 1.0f)
		{
			SetConsoleBounds(
				previousBounds.position.X, previousBounds.position.Y,
				Lerp(previousBounds.scale.X, inp.X, easeOutSine(percent)),
				Lerp(previousBounds.scale.Y, inp.Y, easeOutSine(percent)));

			ConsoleInit();

			percent += 0.0001f * speed;
		}
	}
	break;
	case CONSOLECONTROLTYPE::POSITION_MOVE:
	{
		if (!isPositionInited) return;
		float percent = 0.0f;

		while (percent <= 1.0f)
		{
			SetConsoleBounds(
				Lerp(previousBounds.position.X, inp.X, easeOutSine(percent)),
				Lerp(previousBounds.position.Y, inp.Y, easeOutSine(percent)),
				previousBounds.scale.X, previousBounds.scale.Y);

			ConsoleInit();

			percent += 0.0001f * speed;
		}
	}
	break;
	}
}

void Core::AttentionTextRender()
{

	COORD desktopResol = GetDesktopResolution();
	SetFontSize(15);

	ConsoleControl(CONSOLECONTROLTYPE::SCALE_INIT, COORD{ 800, 500 });
	ConsoleControl(CONSOLECONTROLTYPE::POSITION_INIT, 
		COORD{(SHORT)(desktopResol.X/2),  (SHORT)(desktopResol.Y/2 + -1000)});

	ConsoleControl(CONSOLECONTROLTYPE::POSITION_MOVE,
		COORD{(SHORT)(desktopResol.X/2), (SHORT)(desktopResol.Y/2) });
	

	wcout << L"" << endl;
	wcout << L"" << endl;
	wcout << L"" << endl;
	wcout << L"\t█████╗ ██╗   ██╗████████╗ ██████╗         ██████╗  ██████╗ ██╗   ██╗████████╗███████╗" << endl;
	wcout << L"\t██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗        ██╔══██╗██╔═══██╗██║   ██║╚══██╔══╝██╔════╝" << endl;
	wcout << L"\t███████║██║   ██║   ██║   ██║   ██║        ██████╔╝██║   ██║██║   ██║   ██║   █████╗" << endl;
	wcout << L"\t██╔══██║██║   ██║   ██║   ██║   ██║        ██╔══██╗██║   ██║██║   ██║   ██║   ██╔══╝" << endl;
	wcout << L"\t██║  ██║╚██████╔╝   ██║   ╚██████╔ ═══════ ██║  ██║╚██████╔╝╚██████╔╝   ██║   ███████╗" << endl;
	wcout << L"\t╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝         ╚═╝  ╚═╝ ╚═════╝  ╚═════╝    ╚═╝   ╚══════╝" << endl;
	wcout << L"" << endl;
	wcout << L"" << endl;
	wcout << L"\t제작자 : 구본후, 김강한울" << endl;
	wcout << L"\t제작일 2024 - 06 - 08" << endl;
	wcout << L"" << endl;
	SetColor((int)COLOR::YELLOW);
	wcout << L"\t이 게임은 싱글 모니터 상태여야지 정상적으로 플레이할 수 있다는 점 양해 부탁드립니다. " << endl;
	wcout << L"\t화면이 움직이는 모션이 많이 나올 수 있으니 주의해주시면 감사하겠습니다!" << endl;
	wcout << L"\t즐거운 플레이 되세요!" << endl;
	wcout << L"" << endl;
	wcout << L"" << endl;
	wcout << L"" << endl;
	SetColor((int)COLOR::LIGHT_RED, (int)COLOR::BLACK);
	wcout << L"\t>> 아무 키나 눌러 시작하세요. <<" << endl;
	SetColor((int)COLOR::WHITE);

	Input(INPUTTYPE::WAIT_ANY_KEY);
	system("cls");

}

void Core::DescriptionRender()
{
	SetFontSize(25);

}

SCENEENUM Core::MainSceneRender()
{
	return SCENEENUM();
}

void Core::GamePrepare()
{
}

void Core::GamePlay()
{
}

void Core::GameDescRender()
{
}

void Core::GameExit()
{
}
