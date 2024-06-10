#pragma once

#include "IFlag.h"

#include "RenderQueue.h"
#include "Dialog.h"
#include "ItemList.h"
#include "SquareMap.h"


class Core
{
private:
	Core() 
	{

	}

public:
	static Core* GetInst()
	{
		if(m_pInst == nullptr)
			m_pInst = new Core;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

	static void Init();
	static void Run();
	static void Update(TYPEENUM type, int count);
	
private:

	static COORD Input(INPUTTYPE inputType);
	static void ConsoleControl
	(CONSOLECONTROLTYPE controlType, COORD inp, float speed = 1);

	static void AttentionTextRender();
	static void DescriptionRender();
	static SCENEENUM MainSceneRender();

	static void GamePrepare();
	static void GamePlay();
	static void GameDescRender();
	static void GameExit();


private:
	static Core* m_pInst;
	
public:
	static vector<IFlag*> flags;


};
