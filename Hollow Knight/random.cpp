#include "stdafx.h"
#include "random.h"

HRESULT random::init()
{
	// Randomseed initialization
	srand(GetTickCount());

	return S_OK;
}

void random::release()
{
}

int random::range(int num)
{
	return rand() % num;
}

int random::range(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

float random::range(float num)
{
	//3 / 2 = 1 (integer)
	//3.0 / 2.0 = 1.5 (mistake)
	//rand() => 0 ~ 32767
	//RAND_MAX => 32767
	//rand() / RAND_MAX => Range of values : 0.0f ~ 1.0f

	return ((float)rand() / (float)RAND_MAX) * num;
}

float random::range(float min, float max)
{
	float rnd = ((float)rand() / (float)RAND_MAX);
	return (rnd * (max - min)) + min;
}
