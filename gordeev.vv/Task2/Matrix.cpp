#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
//Конструктор по умолчанию
Matrix::Matrix(void)
{
	size = 0;
	mtx = 0;
}
Matrix::Matrix(int _size) 
{
	array2(_size);
}
//Конструктор инициализатор
Matrix::Matrix(int _size, int fill)
{
	size = _size;
	mtx = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		mtx[i] = new int[size];
		for (int j = 0; j < size; ++j)
			mtx[i][j] = fill;
	}
}
//Конструктор копирования
Matrix::Matrix(const Matrix& matrix)
{
	array2(matrix.size);

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			mtx[i][j] = matrix.mtx[i][j];
}
//Деструктор
Matrix::~Matrix()
{
	for (int i = 0; i < size; ++i)
		delete[] mtx[i];
	delete[] mtx;
	size = 0;
}
//Перегрузка оператора присваивания
Matrix Matrix::operator=(const Matrix& matrix)
{
	if (size == matrix.size)
	{
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				mtx[i][j] = matrix.mtx[i][j];
	}
	else
	{
		throw MatrixExeption(wrongsize, size);
	}
	return *this;
}
//Перегрузка оператора сложения
Matrix Matrix:: operator+(const Matrix& matrix)
{
	Matrix res(size);
	if (size == matrix.size)
	{		
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				res.mtx[i][j] = mtx[i][j] + matrix.mtx[i][j];		
	}
	else
	{
		throw MatrixExeption(wrongsize, size);
	}
	return res;
}
//Перегрузка оператора умножения(Умножение матрицы на матрицу)
Matrix Matrix::operator*(const Matrix& matrix)
{
	Matrix res(size);
	int m;
	if (size == matrix.size)
	{
		for (int rI = 0; rI < size; rI++)
			for (int rJ = 0; rJ < size; rJ++)
			{
				m = 0;
				for (int i = 0; i < size; i++)
				{
					m += mtx[rI][i] * matrix.mtx[i][rJ];
				}
				res[rI][rJ] = m;
			}		
	}
	else
	{
		throw MatrixExeption(wrongsize, size);
	}
	return res;
}
//Перегрузка операции умножения матрицы на число
Matrix Matrix::operator*(int num)
{
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = mtx[i][j] * num;
	return res;
}
//Умножение числа на матрицу
Matrix operator* (int num, Matrix& matrix)
{
	return matrix * num;
}
//Перегрузка операции индексации с контролем выхода за предел массива
int*Matrix:: operator[](int i)
{
	if (i < size)
		return mtx[i];
	else
	{
		throw MatrixExeption(outofArray,size);
		return mtx[0];
	}
}
//Транспонирование матрицы
Matrix Matrix::Transpositione()
{ 
	Matrix res(*this);
	for (int i = 0; i < res.size - 1; i++)
		for (int j = i + 1; j < res.size; j++)
			swap(res.mtx[i][j], res.mtx[j][i]);
	return res;
}
//Проверка на диагональное преобладание
bool Matrix:: DiagonalDominant()
{
	int sum;
	for (int i = 0; i < size; ++i)
	{
		sum = 0;
		for (int j = 0; j < size; ++j)
			if (j != i)
				sum += mtx[i][j];
		if (mtx[i][i] < sum)
			return false;
	}
	return true;
}
void Matrix::ChangeSize(const int _size)
{
	Matrix copy;
	int n = 0;
	if (size > 0) 
	{
		//Копирование
		copy = *this;   
		delete[] mtx; 
		n = size;
		if (_size < n)
			n = _size;
	}
	size = _size;
	mtx = new int* [size];
	for (int i = 0; i < size; ++i)
		mtx[i] = new int[size];
	for (int i = 0; i < size; i++)
	{		
		//Заполнение 0
		for (int j = 0; j < size; j++)
			mtx[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mtx[i][j] = copy.mtx[i][j];
}

void Matrix::array2(int _size)
{
	size = _size;
	mtx = new int* [size];
	for (int i = 0; i < size; ++i)
		mtx[i] = new int[size];
}

//Перегрузка операции >>
istream& operator>>(istream& stream, Matrix& matrix)
{
	int _size;
	stream >> _size;
	matrix.ChangeSize(_size);
	for (int i = 0; i < matrix.size; i++)
		for (int j = 0; j < matrix.size; j++)
			stream >> matrix.mtx[i][j];
	return stream;
}
//Перегрузка операции <<
ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	stream << matrix.size << endl;
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
			stream << matrix.mtx[i][j] << "\t";
		stream << endl;
	}
	return stream;
 }