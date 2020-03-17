#include "Matrix.h"
#include <iostream>
#include <fstream>
Matrix::Matrix()  //конструктор по умолчанию
{
	size = 0; mat = 0;
}
Matrix::Matrix(int _size) //конструктор выделения памяти под матрицу
{
	size = _size;
	mat = new int* [size];
	for (int i = 0; i < size; ++i)
		mat[i] = new int[size];
}
Matrix::Matrix(int _size, int fill) //конструктор выделения памяти под матрицу и заполнение одним числом
{
	size = _size;
	mat = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		mat[i] = new int[size];
		for (int j = 0; j < size; ++j)
			mat[i][j] = fill;
	}

	
}
Matrix::Matrix(const Matrix& m) //конструктор копирования
{
	size = m.size;
	mat = new int* [size];
	for (int i = 0; i < size; ++i)
		mat[i] = new int[size];

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			mat[i][j] = m.mat[i][j];
}
Matrix::~Matrix() 
{
	if (mat != 0)
	{
		for (int i = 0; i < size; ++i)
			delete[] mat[i];
		delete[] mat;
	}
	size = 0;
	mat = 0;
}
Matrix& Matrix::operator=(const Matrix& m) //операция присваивания
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			mat[i][j] = m.mat[i][j];
	return *this;
}
Matrix Matrix::operator+(const Matrix& m) ///операция суммирования двух матриц одинакового размера
{
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.mat[i][j] = mat[i][j] + m.mat[i][j];
	return res;
}
Matrix Matrix::operator-(const Matrix& m) ///операция разности двух матриц одинакового размера
{
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.mat[i][j] = mat[i][j] - m.mat[i][j];
	return res;
}
Matrix Matrix::operator*(const Matrix& m) //операция умножения матриц
{
	Matrix res(size);
	int mul;
	for (int resI = 0; resI < size; ++resI)
		for (int resJ = 0; resJ < size; ++resJ)
		{
			mul = 0;
			for (int i = 0; i < size; ++i)
			{
				mul += mat[resI][i] * m.mat[i][resJ];
			}
			res[resI][resJ] = mul;
		}
	return res;
}
Matrix Matrix::operator*(int num) //операция умножения скаляра на матрицу
{
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = mat[i][j] * num;
	return res;
}
int* Matrix::operator[](int _i) //операция индексации с контролем выхода индекса за границы массива
{
	if (_i < size)
		return mat[_i];
}
void Matrix::transpose() //операция транспонирования матрицы
{
	for (int i = 0; i < size - 1; ++i)
		for (int j = i + 1; j < size; ++j)
			std::swap(mat[i][j], mat[j][i]);
}
bool Matrix::diagonallyDominant() //проверить, обладает ли матрица диагональным преобладанием
{
	int sum;
	for (int i = 0; i < size; ++i)
	{
		sum = 0;
		for (int j = 0; j < size; ++j)
			if (j != i)
				sum += mat[i][j];
		if (mat[i][i] < sum)
			return false;
	}
	return true;
}
std::ostream& operator<< (std::ostream& stream, const Matrix& m)
{
	for (int i = 0; i < m.size; ++i)
	{
		for (int j = 0; j < m.size; ++j)
			stream << m.mat[i][j] << ' ';
		stream << std::endl;
	}
	return stream;
}
std::istream& operator>> (std::istream& stream, Matrix& m)
{
	for (int i = 0; i < m.size; ++i)
		for (int j = 0; j < m.size; ++j)
			stream >> m.mat[i][j];
	return stream;
}