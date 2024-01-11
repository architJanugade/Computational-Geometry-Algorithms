//#pragma once
//#include<iostream>
//#include "Core/base/Vector.h"
//#include "Point.h"
//
//template <typename T>
//class Matrix44 {
//
//public:
//	Matrix44() {}
//    const T* operator [] (T i) const { return m[i]; }
//    T* operator[] (T i) { return m[i]; }
//
//	T m[4][4] = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
//
//
//	Matrix44<T> operator * (const Matrix44 rhs) const;
//	void MultPointMatrix(const Vector<T, DIM3>& Src, Vector<T, DIM3>& dest);
//	void MultVecMatrix(const Vector<T, DIM3>& src, Vector<T, DIM3>& dest);
//	Matrix44<T> MTranspose(const Matrix44 inputM);
//    Matrix44 inverse()
//    {
//        int i, j, k;
//        Matrix44 s;
//        Matrix44 t(*this);
//
//        // Forward elimination
//        for (i = 0; i < 3; i++) {
//            int pivot = i;
//
//            T pivotsize = t[i][i];
//
//            if (pivotsize < 0)
//                pivotsize = -pivotsize;
//
//            for (j = i + 1; j < 4; j++) {
//                T tmp = t[j][i];
//
//                if (tmp < 0)
//                    tmp = -tmp;
//
//                if (tmp > pivotsize) {
//                    pivot = j;
//                    pivotsize = tmp;
//                }
//            }
//
//            if (pivotsize == 0) {
//                // Cannot invert singular matrix
//                return Matrix44();
//            }
//
//            if (pivot != i) {
//                for (j = 0; j < 4; j++) {
//                    T tmp;
//
//                    tmp = t[i][j];
//                    t[i][j] = t[pivot][j];
//                    t[pivot][j] = tmp;
//
//                    tmp = s[i][j];
//                    s[i][j] = s[pivot][j];
//                    s[pivot][j] = tmp;
//                }
//            }
//
//            for (j = i + 1; j < 4; j++) {
//                T f = t[j][i] / t[i][i];
//
//                for (k = 0; k < 4; k++) {
//                    t[j][k] -= f * t[i][k];
//                    s[j][k] -= f * s[i][k];
//                }
//            }
//        }
//
//        // Backward substitution
//        for (i = 3; i >= 0; --i) {
//            T f;
//
//            if ((f = t[i][i]) == 0) {
//                // Cannot invert singular matrix
//                return Matrix44();
//            }
//
//            for (j = 0; j < 4; j++) {
//                t[i][j] /= f;
//                s[i][j] /= f;
//            }
//
//            for (j = 0; j < i; j++) {
//                f = t[j][i];
//
//                for (k = 0; k < 4; k++) {
//                    t[j][k] -= f * t[i][k];
//                    s[j][k] -= f * s[i][k];
//                }
//            }
//        }
//
//        return s;
//    }
//
//    // \brief set current matrix to its inverse
//    const Matrix44<T>& invert()
//    {
//        *this = inverse();
//        return *this;
//    }
//
//
//};
//
//typedef Matrix44<float> Matrix44f;
//
//
