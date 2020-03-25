#include "Matrix.h"
#include <iostream>
#include <fstream>
Exception::Exception(ExceptionType _error)
{
	error = _error;
}
Matrix::Matrix()  //����������� �� ���������
{
	size = 0; mat = 0;
}
Matrix::Matrix(int _size) //����������� ��������� ������ ��� �������
{
	create(_size);
}
Matrix::Matrix(int _size, int fill) //����������� ��������� ������ ��� ������� � ���������� ����� ������
{
	create(_size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			mat[i][j] = fill;	
}
Matrix::Matrix(const Matrix& m) //����������� �����������
{
	create(m.size);

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			mat[i][j] = m.mat[i][j];
}
Matrix::~Matrix() 
{
	del();
}
Matrix& Matrix::operator=(const Matrix& m) //�������� ������������
{
	if (size != m.size)
	{
		del();
		create(m.size);
	}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			mat[i][j] = m.mat[i][j];
	return *this;
}
Matrix Matrix::operator+(const Matrix& m) ///�������� ������������ ���� ������ ����������� �������
{
	Matrix res;
	if (size == m.size)
	{
		res = *this;
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.mat[i][j] += m.mat[i][j];
	}
	else
		throw Exception(ExceptionType::sizeError);
	return res;
}
Matrix Matrix::operator*(const Matrix& m) //�������� ��������� ������
{
	Matrix res;
	if (size == m.size)
	{
		res = *this;
		for (int resI = 0; resI < size; ++resI)
			for (int resJ = 0; resJ < size; ++resJ)
			{
				res.mat[resI][resJ] = 0;
				for (int i = 0; i < size; ++i)
				{
					res.mat[resI][resJ] += (mat[resI][i] * m.mat[i][resJ]);
				}
			}
	}
	else
		throw Exception(ExceptionType::sizeError);
	return res;
}
Matrix Matrix::operator*(int num) //�������� ��������� ������� �� ������
{
	Matrix res = *this;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.mat[i][j] *= num;
	return res;
}
Matrix operator* (int num, Matrix& m) //�������� ��������� ������� �� �������
{
	return m * num;
}
int* Matrix::operator[](int _i) //�������� ���������� � ��������� ������ ������� �� ������� �������
{
	if (_i >= 0 && _i < size)
		return mat[_i];
	else 
		throw Exception(ExceptionType::outOfBoundsMatrix);
}
Matrix Matrix::transpose() //�������� ���������������� �������
{
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = mat[j][i];
	return res;
}
bool Matrix::diagonallyDominant() //���������, �������� �� ������� ������������ �������������
{
	int c = 0;
	for (int i = 0; i < size; ++i)
	{
		int sum = -abs(mat[i][i]);
		for (int j = 0; j < size; ++j)
			sum += abs(mat[i][j]);
		if (sum > 0)
			return false;
		else
			if (sum == abs(mat[i][i]))
				c++;
	}
	if (c == size)
		return false;
	else
		return true;
}
std::ostream& operator<< (std::ostream& stream, const Matrix& m)
{
	stream << m.size;
	for (int i = 0; i < m.size; ++i)
	{
		stream << std::endl;
		for (int j = 0; j < m.size; ++j)
			stream << m.mat[i][j] << ' ';
	}
	return stream;
}
std::istream& operator>> (std::istream& stream, Matrix& m)
{
	int size;
	stream >> size;
	if (m.size != size)
		m.del();
		m.create(size);
	for (int i = 0; i < m.size; ++i)
		for (int j = 0; j < m.size; ++j)
			stream >> m.mat[i][j];
	return stream;
}
void Matrix::create(int _size)
{
	size = _size;
	mat = new int* [size];
	for (int i = 0; i < size; ++i)
		mat[i] = new int[size];
}
void Matrix::del()
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