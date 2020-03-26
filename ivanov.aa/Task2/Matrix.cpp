#include "Matrix.h"
#include <iostream>
#include <fstream>
Matrix::Matrix()
{
	dim = 0;
	matr = NULL;
}

Matrix::Matrix(const Matrix& c)
{
	dim = c.dim;
	this->MemSet(c.dim);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			matr[i][j] = c.matr[i][j];
		}
	}
}

Matrix::Matrix(int _dim)
{
	dim = abs(_dim);
	this->MemSet(dim);
	this->ZeroSet();
}

Matrix::Matrix(int _dim, int zap)
{
	dim = abs(_dim);
	this->MemSet(dim);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			matr[i][j] = zap;
		}
	}
}

Matrix::~Matrix()
{
	this->MemFree();
}

void Matrix::MemFree(void)
{
	for (int i = 0; i < dim; i++)
	{
		delete[] matr[i];
	}
	if (matr != NULL)
		delete[] matr;
	matr = NULL;
	dim = 0;
	return;
}

void Matrix::MemSet(const int _dim)
{
	if (_dim == 0)
	{
		dim = 0;
		matr = NULL;
		return;
	}
	dim = abs(_dim);
	matr = new int* [dim];
	for (int i = 0; i < dim; i++)
	{
		matr[i] = new int[dim];
	}
	return;
}

void Matrix::ZeroSet(void)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			matr[i][j] = 0;
		}
	}
}

void Matrix::Transpos(void)
{
	Matrix cop(dim);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cop[i][j] = matr[j][i];
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			matr[i][j] = cop[i][j];
		}
	}
	cop.MemFree();
	return;
}

bool Matrix::DiagPreob()
{
	bool ans = true;
	for (int i = 0; i < dim; i++)
	{
		int ch = 0;
		for (int j = 0; j < dim; j++)
		{
			ch += abs(matr[i][j]);
		}
		ch -= abs(matr[i][i]);
		if (abs(matr[i][i]) <= ch)
			ans = false;
	}
	return ans;
}

Matrix& Matrix::operator=(const Matrix& c)
{
	this->MemFree();
	this->MemSet(c.dim);
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			matr[i][j] = c.matr[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& c)
{
	Matrix res(this->dim);
	if (this->dim != c.dim)
	{
		std::cout << "Ошибка размерности слагаемых матриц\n";
		res.ZeroSet();
		return res;
	}
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			res[i][j] = matr[i][j] + c.matr[i][j];
		}
	}
	return res;
}

Matrix Matrix::operator-(const Matrix& c)
{
	Matrix res(this->dim);
	if (this->dim != c.dim)
	{
		std::cout << "Ошибка размерности вычитаемых матриц\n";
		res.ZeroSet();
		return res;
	}
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			res[i][j] = matr[i][j] - c.matr[i][j];
		}
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& c)
{
	Matrix res(this->dim);
	if (this->dim != c.dim)
	{
		std::cout << "Ошибка размерности умножаемых матриц\n";
		res.ZeroSet();
		return res;
	}
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			res.matr[i][j] = 0;
			for (int k = 0; k < c.dim; k++)
			{
				res.matr[i][j] += matr[i][k] * c.matr[k][j];
			}
		}
	}
	return res;
}

Matrix Matrix::operator*(const int ch)
{
	Matrix res(this->dim);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			res.matr[i][j] = matr[i][j] * ch;
		}
	}
	return res;
}

Matrix operator*(const int ch, const Matrix& c)
{
	Matrix res(c.dim);
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			res.matr[i][j] = c.matr[i][j] * ch;
		}
	}
	return res;
}

std::ofstream& operator<<(std::ofstream& out, Matrix& c)
{
	out << c.dim << std::endl;
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			out << c.matr[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Matrix& c)
{
	c.MemFree();
	in >> c.dim;
	c.MemSet(c.dim);
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			in >> c.matr[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& c)
{
	if (c.dim == 0)
	{
		out << "Матрица пуста";
		return out;
	}
	out << "Вывод матрицы размерности " << c.dim << std::endl;
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			out << c.matr[i][j] << " ";
		}
		out << std::endl;
	}
	out << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& c)
{
	c.MemFree();
	std::cout << "Введите размерность матрицы: ";
	in >> c.dim;
	c.MemSet(c.dim);
	for (int i = 0; i < c.dim; i++)
	{
		for (int j = 0; j < c.dim; j++)
		{
			std::cout << "[" << i << "]" << "[" << j << "] = ";
			in >> c.matr[i][j];
		}
	}
	return in;
}

int*& Matrix::operator[](int index)
{
	if (index >= 0 && index < dim)
		return this->matr[index];
	else
	{
		std::cout << "Переход за границу по строке\n";
		return this->matr[0]; //!!!!!!!!!
	}
}


