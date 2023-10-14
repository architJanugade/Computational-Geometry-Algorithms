#pragma once

#include "Point.h"
#include "Core/base/Core.h"
#include <algorithm>

double areaTriangle2D(const Point2d& a, const Point2d& b, const Point2d& c);


int orientation2D(const Point2d& a, const Point2d& b, const Point2d& c);

template<typename T>
inline T sphericalTheta(const Vector<T, DIM3>& v);


template<typename T>
const T& clamp(const T& x, const T& upper, const T& lower) {
	return std::min(upper, std::max(x, lower));
}
template<typename T>
inline T sphericalTheta(const Vector<T, DIM3>& v)
{
	return acos(clamp(v[Z] , -1 , 1);
}

template<typename T>
inline T sphercialPhi(const Vector<T, DIM3>& v)
{
	T p = atan2(v[Y], v[X]);
	return (p < 0) p + 2 * M_PI : p;
}
template<typename T> inline T cosTheta(const Vector<T , DIM3>& w) { return w[2]; }

template<typename T>
inline T sinTheta(const Vector<T, DIM3>& w)
{
    T cosThetaSquared = cosTheta(w) * cosTheta(w);
    T sinThetaSquared = 1 - cosThetaSquared;

    return sqrt(sinThetaSquared);
}


template<typename T>
inline T cosPhi(const Vector<T,DIM3>& w)
{
    T sintheta = sinTheta(w);
    if (sintheta == 0) return 1;
    return clamp<T>(w[0] / sintheta, -1, 1);
}

template<typename T>
inline T sinPhi(const Vector<T,DIM3>& w)
{
    T sintheta = sinTheta(w);
    if (sintheta == 0) return 0;
    return clamp<T>(w[1] / sintheta, -1, 1);
}


