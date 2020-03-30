#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int size;
	int** arr;
public:
	Matrix();
	Matrix(const Matrix& matrix);
	Matrix(int _size);
	Matrix(int _size, int k);
	~Matrix();
	Matrix& operator=(const Matrix& matrix);
	Matrix operator + (const Matrix matrix);
	Matrix operator - (const Matrix matrix);
	Matrix operator *(int k);
	Matrix operator *(const Matrix& matrix);
	int* operator[](int i);
	friend ostream& operator << (ostream& out, const Matrix& matrix);
	friend istream& operator >> (istream& in, Matrix& matrix);
	Matrix Transposition();
	bool CheckDiag();
	friend void Create(Matrix& matrix, int _size);
	friend void Delete(Matrix& matrix);
};