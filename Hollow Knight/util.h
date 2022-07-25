#pragma once
//=============================================================
//	## namespace ## MY_UTIL
//=============================================================

#define PI 3.1415926f
#define PI2 (PI * 2)
#define RADIAN 3.1415926f/180.0f

// The value to use later when rotating the image
#define PI_2 (PI / 2) //90 degrees
#define PI_4 (PI / 4) //45 degrees
#define PI_8 (PI / 8) //22.5 degrees

namespace _UTIL
{
	// The distance between two points
	float getDistance(float startX, float startY, float endX, float endY);
	// The angle between two points
	float getAngle(float startX, float startY, float endX, float endY);
};

