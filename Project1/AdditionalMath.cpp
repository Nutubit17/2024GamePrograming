#include "AdditionalMath.h"

#define _USE_MATH_DEFINES
#include <math.h>

int Clamp(int value, int min, int max)
{
	if (value <= min)return min;
	if (value >= max) return max;
	else return value;
}

float Clamp01(float value)
{
	if (value <= 0)return 0;
	if (value >= 1) return 1;
	else return value;
}

float Lerp(float min, float max, float percent)
{
	return min + (max - min) * Clamp01(percent);
}

float easeOutSine(float x)
{
	return sin(x*x * M_PI / 2);
}
