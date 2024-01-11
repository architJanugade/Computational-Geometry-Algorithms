#pragma once
#include <array>
#include <iostream>

#include "Core.h"

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2


	template<class coordinate_type, size_t dimension = DIM3>
	class Vector
	{
		static_assert(std::is_arithmetic<coordinate_type>::value, "Vector class only takes in arithmatic datatypes");
		static_assert(dimension >= DIM2, "Dimensions of Vector class cannot be less than 2");
		std::array<coordinate_type, dimension> coords;

		friend float dotProduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2);

	public:
		Vector() {}
		Vector(std::array<coordinate_type, dimension> _coords) : coords(_coords) {}
		Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) :coords({ _x , _y , _z }) {}
		Vector(coordinate_type _x, coordinate_type _y) : coords({ _x , _y }) {}

		//Equality check
		inline bool operator==(const Vector<coordinate_type, dimension>& _other) const;

		//not equal
		inline bool operator!=(const Vector<coordinate_type, dimension>& _other);


		//Addition
		Vector<coordinate_type, dimension> operator+(const Vector<coordinate_type, dimension>&) const;

		//Substraction
		Vector<coordinate_type, dimension> operator-(const Vector<coordinate_type, dimension>&) const;

		//lessthan
		bool operator<(const Vector<coordinate_type, dimension>&);

		//Greaterthan
		bool operator> (const Vector<coordinate_type, dimension>&);

		coordinate_type operator[](int) const;

		Vector<coordinate_type, dimension> assign(int dim, coordinate_type _value);

		float magnitude() const;


		void Normalize() const;

	};




	typedef Vector<float, DIM2> Vector2f;
	typedef Vector<float, DIM3> Vector3f;

	

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension>& _other) const
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (isEqualD(coords[i], _other.coords[i]))
			{
				return false;
			}
			return true;
		}
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension>& _other)
	{
		return !(*this == _other.coords);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& _other) const
	{
		std::array<coordinate_type, dimension> temp;
		for (size_t i = 0; i < dimension; i++)
		{
			temp[i] = coords[i] + _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& _other) const
	{
		std::array<coordinate_type, dimension> temp;
		for (size_t i = 0; i < dimension; i++)
		{
			temp[i] = coords[i] - _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp);
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator<(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (this->coords[i] < _other.coords[i])
			{
				return true;
			}
			else if(this->coords[i] > _other.coords[i])
			{
				return false;
			}
		}
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator>(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (this->coords[i] > _other.coords[i])
			{
				return true;
			}
			else if (this->coords[i] < _other.coords[i])
			{
				return false;
			}
		}
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline coordinate_type Vector<coordinate_type, dimension>::operator[](int _index) const
	{
		if (_index >= coords.size())
		{
			std::cout << "Index out of bounds";
			return coordinate_type();
		}
		return coords[_index];
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::assign(int dim, coordinate_type _value)
	{
		if (dim >= coords.size())
		{
			std::cout << "Index out of bounds";

		}
		coords[dim] = _value;
		
	}



	template<class coordinate_type, size_t dimension>
	inline float Vector<coordinate_type, dimension>::magnitude() const
	{
		float value = 0.0f;

		for (size_t i = 0; i < dimension; i++)
		{
			value += pow(coords[i], 2.0);
		}


		return sqrt(value);
	}

	template<class coordinate_type, size_t dimension>
	inline void Vector<coordinate_type, dimension>::Normalize() const
	{
		auto mag = magnitude();
		for (size_t i = 0; i < dimension ; i++)
		{
			assign(i, coords[i] / mag);
		}
	}

	


	template<class coordinate_type , size_t dimension>
	float dotProduct(const Vector<coordinate_type,dimension>& v1 , const Vector<coordinate_type,dimension>& v2)
	{
		if (v1.coords.size() != v2.coords.size())
		{
			return FLT_MIN;
		}
		float product = 0.0f;
		for (size_t i= 0; i < dimension; i++)
		{
			product += v1[i] * v2[i];
		}
		return product;
	}

	float crossProduct2D(Vector2f v1 , Vector2f v2);
	Vector3f crossProduct3D(Vector3f v1 , Vector3f v2);




