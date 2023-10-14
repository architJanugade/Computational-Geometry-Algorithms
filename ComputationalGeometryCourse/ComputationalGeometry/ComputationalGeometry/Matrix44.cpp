#include "Matrix44.h"

template<typename T>
Matrix44<T>  Matrix44<T>::operator*(const Matrix44 rhs) const
{
	Matrix44<T> mult;
	for (uint16_t i = 0; i < 4; i++)
	{
		for (uint16_t j = 0; j < 4; j++)
		{
			mult[i][j] = m[i][0] * rhs[0][j] +
						m[i][1] * rhs[1][j] +
						m[i][2] * rhs[2][j] +
						m[i][3] * rhs[3][j];
		}
	}
	return mult;
}

template<typename T>
void Matrix44<T>::MultPointMatrix(const Vector<T, DIM3>& Src, Vector<T, DIM3>& dest)
{
	T a, b, c, w;

	a = Src[0] * x[0][0] + Src[1] * x[1][0] + Src[2] * x[2][0] + x[3][0];
	b = Src[0] * x[0][1] + Src[1] * x[1][1] + Src[2] * x[2][1] + x[3][1];
	c = Src[0] * x[0][2] + Src[1] * x[1][2] + Src[2] * x[2][2] + x[3][2];
	w = Src[0] * x[0][3] + Src[1] * x[1][3] + Src[2] * x[2][3] + x[3][3];

	dst[X] = a / w;
	dst[Y] = b / w;
	dst[Z] = c / w;



}

template<typename T>
void Matrix44<T>::MultVecMatrix(const Vector<T, DIM3>& src, Vector<T, DIM3>& dest)
{
	T a, b, c;

	a = src[0] * x[0][0] + src[1] * x[1][0] + src[2] * x[2][0];
	b = src[0] * x[0][1] + src[1] * x[1][1] + src[2] * x[2][1];
	c = src[0] * x[0][2] + src[1] * x[1][2] + src[2] * x[2][2];

	dst[X] = a;
	dst[Y] = b;
	dst[Z] = c;
}

template<typename T>
Matrix44<T> Matrix44<T>::MTranspose(const Matrix44 inputM)
{
	Matrix44<T> transpMat;
	for (uint16_t i = 0; i < 4; i++)
	{
		for (uint16_t j = 0; j < 4; j++)
		{
			transpMat[i][j] = m[j][i];
		}
	}
	return Matrix44<T>();
}




