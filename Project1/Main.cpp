#include "IncludePack.h"
#include "Unit.h"
#include "Logic.h"



int main() 
{
	Core* core = Core::GetInst();
	core->Init();
	core->Run();

	return 0;
}