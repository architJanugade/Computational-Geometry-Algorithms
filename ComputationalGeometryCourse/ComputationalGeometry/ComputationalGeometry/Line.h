#pragma once

#include "Core/base/Vector.h"

template<class coordinate_type ,int dim =  DIM3>
class Line
{
	Vector<coordinate_type, dim> dir;
	Vector<coordinate_type, dim> point;
	Line();
public:

	Line(Vector<coordinate_type, dim>& p1, coordinate_type, dim > & p2)
	{
		dir = p2 - p1;
		point = p1;
	}

	Vector<coordinate_type, dim> getPoint();
	Vector<coordinate_type, dim> getDir();

};


