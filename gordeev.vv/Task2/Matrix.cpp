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
	size = _size;
	mtx = new int* [size];
	for (int i = 0; i < size; ++i)
		mtx[i] = new int[size];
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
	size = matrix.size;
	mtx = new int* [size];
	for (int i = 0; i < size; ++i)
		mtx[i] = new int[size];

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
		cout << "Присваивание невозможно из-за разного размера матриц" << endl;		
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
		cout << "Сложение невозможно из-за разного размера матриц" << endl;		
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
		cout << "Умножение невозможно из-за разного размера матриц" << endl;
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
		cout << "Неверный индекс" << endl;	
		return mtx[0];
	}
}
//Транспонирование матрицы
void Matrix::Transpositione()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			swap(mtx[i][j], mtx[j][i]);
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
//Перегрузка операции >>
istream& operator>>(istream& stream, Matrix& matrix)
{
	for (int i = 0; i < matrix.size; i++)
		for (int j = 0; j < matrix.size; j++)
			stream >> matrix.mtx[i][j];
	return stream;
}
//Перегрузка операции <<
ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
			stream << matrix.mtx[i][j] << ' ';
		stream << endl;
	}
	return stream;
 }