#pragma once
#include <iostream>


class Matrix
{
private:
	int size;
	int** matrix;
	void Matr(int size)
	{
		matrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
	}
public:

	Matrix();
	Matrix(int _size, int** _matrix);
	Matrix(int s);
	Matrix(const Matrix& matr);	
	~Matrix();

	Matrix T();
	bool DiagPreob();

	Matrix operator +(Matrix& m);
	Matrix operator *(Matrix& m);

	int* operator [](int i);
	Matrix& operator = (const Matrix& m);
	friend Matrix operator *(int num, const Matrix& m);
	friend std::ostream& operator << (std::ostream& stream, const Matrix& m);
	friend std::istream& operator >> (std::istream& stream, Matrix& m);
};
Matrix operator *(int num, const Matrix& m);
std::ostream& operator << (std::ostream& stream, const Matrix& m);
std::istream& operator >> (std::istream& stream, Matrix& m);
