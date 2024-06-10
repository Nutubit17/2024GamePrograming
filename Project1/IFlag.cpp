#include "IFlag.h"



bool IFlag::IsPlayer()
{
	return ((int)type & (int)TYPEENUM::Player) > 0;
}

TYPEENUM IFlag::GetType()
{
	return (TYPEENUM)((int)type & 0b111);
}
