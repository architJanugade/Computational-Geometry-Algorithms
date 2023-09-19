#include "GeoUtils.h"


double areaTriangle2D(const Point2d& a, const Point2d& b, const Point2d& c)
{
	auto AB = b - a;
	auto AC = c - a;
	auto result = crossProduct2D(AB, AC);

	return result/2;
}

int orientation2D(const Point2d& a, const Point2d& b, const Point2d& c)
{
	auto area = areaTriangle2D(a, b, c);

	Vector2f ab = b - a;
	Vector2f ac = c - a;


	if (area > 0 && area < TOLOERENCE)
		area = 0;
	if (area<0 && area > TOLOERENCE)
		area = 0;
	if (area > 0)
		return RELATIVE_POSITION::LEFT;
	if (area < 0)
		return RELATIVE_POSITION::RIGHT;
	if (ab[X] * ac[X] < 0 && ab[Y] * ac[Y] < 0)
		return RELATIVE_POSITION::BEHIND;
	if (ab.magnitude() < ac.magnitude())
		return RELATIVE_POSITION::BEYOND;
	if (a == c)
		return RELATIVE_POSITION::ORIGIN;
	if (b == c)
		return RELATIVE_POSITION::DESTINATION;

	return RELATIVE_POSITION::BETWEEN;

}
