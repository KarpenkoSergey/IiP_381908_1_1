#pragma once
#include <iostream>
using namespace std;

class Matrix {
	private:
		int size;
		int **m;
    public:
		Matrix();
		Matrix(int _size);
		Matrix(const Matrix& mat);
		Matrix(int _size,  int k);
		~Matrix();
		Matrix& operator = (const Matrix& mat);
		Matrix operator + (const Matrix& mat);
		Matrix operator - (const Matrix& mat);
	    int* operator[] (int i);
		Matrix operator *(int k);
		Matrix operator *(const Matrix& mat);
		friend ostream& operator << (ostream&, const Matrix& mat);
		friend istream& operator >> (istream&, Matrix& m);
		friend void trsp(const Matrix& mat);
		friend bool diag_dm(const Matrix& mat);
};
