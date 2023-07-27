#include "Vector.h"

inline float crossProduct2D(Vector2f v1, Vector2f v2)
{
	return v1[X] * v2[Y] - v1[Y] * v2[X];
}

Vector3f crossProduct3D(Vector3f v1, Vector3f v2)
{
	float _x, _y, _z;
	_x = v1[Y] * v2[Z] - v1[Z] * v1[Y];
	_y = -(v2[Z] * v1[X] - v1[Z] * v2[X]);
	_z = v1[X] * v2[Y] - v2[X] * v1[Y];
	return Vector3f(_x , _y , _z);
}
