#pragma once

#include <math.h>

#define TOLOERENCE 0.0000001

enum RELATIVE_POSITION
{
	LEFT,RIGHT,BEHIND,BETWEEN,BEYOND,ORIGIN,DESTINATION
};


static bool isEqualD(double x, double y)
{
	return fabs(x - y) < TOLOERENCE;
}


