#include "Matrix.h"
#include <ctime>
#include <iostream>

Matrix::Matrix() //по умолчанию
{
	size = 0;	
	matrix = NULL;
}

Matrix::Matrix(int s) //преобразование типа int в Matrix
{
	srand(time(NULL));
	size = s;
	Matr(s);
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			matrix[i][j] = 1 + rand() % 10;
		}
	}
}

Matrix::Matrix(int _size, int** _matrix) // инициализация
{
	size = _size;
	matrix = _matrix;
}

Matrix::Matrix(const Matrix& matr)  // конструктор копирования
{
	size = matr.size;
	Matr(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = matr.matrix[i][j];
		}
	}
}

Matrix::~Matrix() // деконструктор
{
	for (int i = 0; i < size; i++)
	{
		if (matrix[i] != NULL)
		{
			delete[] matrix[i];
			matrix[i] = NULL;
		}
	}
	if (matrix != NULL)
	{
		delete[] matrix;
		matrix = NULL;
		size = 0;
	}
}

Matrix Matrix::T()
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
	return *this;
}

Matrix Matrix::operator +(Matrix& m) 
{
	if (size = m.size)
	{
		Matrix matr(m.size);
		for (int i = 0; i < m.size; i++)
		{
			for (int j = 0; j < m.size; j++)
			{
				matr[i][j] = matrix[i][j] + m.matrix[i][j];
			}
		}
		return matr;
	}
	else
		std::cout << "Error: size";
}

Matrix Matrix::operator *(Matrix& m)
{
	Matrix matr(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int sum = 0;
			for (int s = 0; s < size; s++)
			{
				sum += matrix[i][s] * m.matrix[s][j];
			}
			matr[i][j] = sum;
		}
	}
	return matr;
}

bool Matrix::DiagPreob()
{
	int sum = 0;
	int sumd = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
				sum += matrix[i][j];
			else
				sumd += matrix[i][j];
		}
	}

	if (sumd >= sum)
		return true;
	else 
		return false;
}

int* Matrix::operator [](int i)
{
	if (i < 0 || i > size)
		abort();
	else
		return matrix[i];
}

Matrix& Matrix::operator = (const Matrix& m)
{
	Matr(m.size);
	size = m.size;	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}

Matrix operator *(int num, const Matrix& m)
{
	Matrix matr(m.size);
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			matr[i][j] = m.matrix[i][j] * num;
		}
	}
	return matr;
}

std::ostream& operator << (std::ostream& stream, const Matrix& m)
{
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			stream << m.matrix[i][j] << " ";
		}
		stream << std::endl;
	}
	return stream;
}

std::istream& operator >> (std::istream& stream, Matrix& m)
{
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			stream >> m.matrix[i][j];
		}
	}
	return stream;
}