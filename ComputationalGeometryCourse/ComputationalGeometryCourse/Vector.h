#pragma once
#include <array>
#include <iostream>

namespace jmk {
#define DIM2 2
#define DIM3 3

	template<class cooridnate_type, size_t dimension = DIM3>
	class Vector
	{
		static_assert(std::is_arithmetic<cooridnate_type>, "Vector class only takes in arithmatic datatypes");
		static_assert(dimension >= DIM2, "Dimensions of Vector class cannot be less than 2");
		std::array<cooridnate_type, dimension> coords;


	};

}
