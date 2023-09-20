#include "Line.h"

template<class coordinate_type, int dim>
inline Vector<coordinate_type, dim> Line<coordinate_type, dim>::getPoint()
{
	return point;
}

template<class coordinate_type, int dim>
Vector<coordinate_type, dim> Line<coordinate_type, dim>::getDir()
{
	return dir;
}
