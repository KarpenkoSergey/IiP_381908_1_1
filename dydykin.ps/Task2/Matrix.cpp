#include <iostream>
#include "Matrix.h"

Matrix::Matrix()
{
	arr = 0;
	size = 0;
}

Matrix::Matrix(const Matrix& matrix)
{
	Create(*this, matrix.size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			arr[i][j] = matrix.arr[i][j];
}

Matrix::Matrix(int _size)
{
	Create(*this, _size);
}

Matrix::Matrix(int _size, int k)
{
	Create(*this, _size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			arr[i][j] = k;
}

Matrix::~Matrix()
{
	arr = 0;
	size = 0;
	Delete(*this);
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (size != matrix.size) {
		Delete(*this);
		Create(*this, matrix.size);
	}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			arr[i][j] = matrix.arr[i][j];
	return *this;
}

Matrix Matrix::operator+(const Matrix matrix)
{
	Matrix res(size);
	if (size == matrix.size)
	{
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.arr[i][j] = arr[i][j] + matrix.arr[i][j];
	}
	else throw 1;
	return res;
}

Matrix Matrix::operator-(const Matrix matrix)
{
	Matrix res(size);
	if (size == matrix.size)
	{
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.arr[i][j] = arr[i][j] - matrix.arr[i][j];
	}
	else throw 1;
	return res;
}

Matrix Matrix::operator*(int k)
{
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.arr[i][j] = arr[i][j] * k;
	return res;
}

Matrix Matrix::operator*(const Matrix& matrix)
{
	Matrix res(size);
	if (size == matrix.size)
	{
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j) {
				res.arr[i][j] = 0;
				for (int k = 0; k < size; k++)
				{
					res.arr[i][j] += arr[i][j] * matrix.arr[i][j];
				}
			}
		return res;
	}
	else throw 1;

}

int* Matrix::operator[](int i)
{
	if (i >= 0 && i < size)
		return arr[i];
	else throw 2;
}

Matrix Matrix::Transposition()
{
	Matrix res(size);
	for (int i = 0; i < res.size; ++i)
		for (int j = 0; j < res.size; ++j)
			res.arr[i][j] = arr[j][i];
	return res;
}

bool Matrix::CheckDiag()
{
	int sum = 0;
	int f = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			if (i != j)
				sum += abs(arr[i][j]);
		if (sum > arr[i][i])
			return 0;
		if (sum < arr[i][i])
			f = 1;
		sum = 0;
	}
	return f;
}

ostream& operator<<(ostream& out, const Matrix& matrix)
{
	out << matrix.size << endl;
	for (int i = 0; i < matrix.size; ++i) {
		for (int j = 0; j < matrix.size; ++j)
			out << matrix.arr[i][j] << " ";
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matrix& matrix)
{
	int _size;
	in >> _size;
	if (_size == matrix.size)
	{
		for (int i = 0; i < matrix.size; ++i)
			for (int j = 0; j < matrix.size; ++j)
				in >> matrix.arr[i][j];
		return in;
	}
	else throw 1;
}


void Create(Matrix& matrix, int _size)
{
	matrix.size = _size;
	matrix.arr = new int* [matrix.size];
	for (int i = 0; i < matrix.size; ++i) {
		matrix.arr[i] = new int[matrix.size];
	}
}

void Delete(Matrix& matrix)
{
	if (matrix.size > 0)
	{
		for (int i = 0; i < matrix.size; ++i)
			delete[] matrix.arr[i];
		delete[] matrix.arr;
	}
}