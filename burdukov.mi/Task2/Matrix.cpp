#include <iostream>
#include "Matrix.h"


//Констукторы и Деконструкторы
Matrix::Matrix(int n) {
	size = n;

	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
}
Matrix::Matrix() {
	size = 0;
	matrix = 0;
}
Matrix::Matrix(const Matrix& c) {
	size = c.size;
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = c.matrix[i][j];
}
Matrix::Matrix(int n, int k) {
	size = n;
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = k;
}
Matrix::~Matrix() {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	size = 0;
}

//Перегрузки
Matrix& Matrix::operator=(const Matrix& c) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	size = c.size;
	matrix = new int* [size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = c.matrix[i][j];
	return *this;
}
Matrix Matrix::operator+(const Matrix& c) {
	Matrix res(size);
	if (size != c.size) throw 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res.matrix[i][j] = matrix[i][j] + c.matrix[i][j];
	return res;
}
std::istream& operator >> (std::istream& in, Matrix& c) {
	for (int i = 0; i < c.size; i++)
		delete[] c.matrix[i];
	delete[] c.matrix;
	in >> c.size;
	c.matrix = new int* [c.size];
	for (int i = 0; i < c.size; i++) {
		c.matrix[i] = new int[c.size];
	}
	for (int i = 0; i < c.size; i++)
		for (int j = 0; j < c.size; j++)
			in >> c.matrix[i][j];
	return in;
}
std::ostream& operator << (std::ostream& out, const Matrix& c) {
	out << c.size << std::endl;
	for (int i = 0; i < c.size; i++) {
		for (int j = 0; j < c.size; j++)
			out << c.matrix[i][j] << " ";
		out << std::endl;
	}
	return out;
}
Matrix Matrix::operator*(int k) {
	Matrix res(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res.matrix[i][j] = matrix[i][j] * k;
	return res;
}
Matrix Matrix::operator*=(const Matrix& c) {
	*this = *this * c;
	return *this;
}
Matrix Matrix::operator*=(int k) {
	*this = *this * k;
	return *this;
}
Matrix Matrix::operator*(const Matrix& c) {
	Matrix res(size);
	if (c.size != size) throw 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			res.matrix[i][j] = 0;
			for (int k = 0; k < size; ++k)
				res.matrix[i][j] += matrix[i][k] * c.matrix[k][j];
		}
	return res;
}
int* Matrix::operator[](int i) {
	if (i >= 0 && i < size)
		return matrix[i];
	else throw 2;

}

//Функции
Matrix Transposition(const Matrix& c) {
	Matrix res(c.size);
	for (int i = 0; i < c.size; i++)
		for (int j = 0; j < c.size; j++)
			res.matrix[i][j] = c.matrix[j][i];
	return res;
}
bool CheckDiag(const Matrix& c) {
	for (int i = 0; i < c.size; i++) {
		int count = 0;
		for (int j = 0; j < c.size; j++) {
			count += c.matrix[i][j];
		}
		if (count >= 2 * c.matrix[i][i]) return 0;
	}
	return 1;
}
