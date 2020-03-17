#pragma once
#include <iostream>
class Matrix
{
private:
	int size;
	int** mat;
public:
	Matrix();
	Matrix(int _size);
	Matrix(int _size, int fill);
	Matrix(const Matrix& m);
	~Matrix();
	Matrix& operator=(const Matrix& m);
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix operator*(int num);
	int* operator[](int _i);
	void transpose();
	bool diagonallyDominant();
	friend std::ostream& operator<< (std::ostream& stream, const Matrix& m);
	friend std::istream& operator>> (std::istream& stream, Matrix& m);
};
std::ostream& operator<< (std::ostream& stream, const Matrix& t);
std::istream& operator>> (std::istream& stream, Matrix& t);



