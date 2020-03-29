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
	    Matrix trsp();
	    friend Matrix operator *( int k, const Matrix& mat);
		friend ostream& operator << (ostream&, const Matrix& mat);
		friend istream& operator >> (istream&, Matrix& m);
	    bool diag_dm();
		friend void make(Matrix& mat, int _size);
		friend void del(Matrix& mat);
};

enum class ExceptionType {sizeError, outArray};
struct Exception {
	ExceptionType err;
	Exception(ExceptionType _err);
};
