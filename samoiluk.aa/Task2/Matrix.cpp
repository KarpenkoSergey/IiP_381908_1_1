#include <clocale>
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Matrix.h"
using namespace std;

// Конструктор по умолчанию
Matrix::Matrix() {
	size = 0;
	ar = 0;
}

// Выделение памяти
void Matrix::Create(int _size) {
	size = _size;
	ar = new int* [size];
	for (int i = 0; i < size; ++i)
		ar[i] = new int[size];
}

Matrix::Matrix(int _size) {
	Create(_size);
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			ar[i][j] = rand() % 100;
}

// Копирование
Matrix::Matrix(const Matrix& m) {
	Create(m.size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			ar[i][j] = m.ar[i][j];
}


// Инициализатор
Matrix::Matrix(int _size, int fill) {
	Create(_size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			ar[i][j] = fill;
}


// Деструктор
Matrix::~Matrix() {
	for (int i = 0; i < size; ++i)
		if (ar[i] != NULL)
			delete[] ar[i];
	if (ar != NULL)
		delete[] ar;
	size = 0;
}

// Перегрузка операции присваивания
Matrix& Matrix::operator=(const Matrix& m) {

	if (size == m.size) {
		Create(m.size);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				ar[i][j] = m.ar[i][j];
		return *this;
	}
	else throw ExMatrix(wrongSize, size);
}

// Перегрузка операции сложения матриц
Matrix Matrix::operator+(const Matrix& m) {
	if (size == m.size) {
		Matrix res;
		res.Create(size);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.ar[i][j] = ar[i][j] + m.ar[i][j];
		return res;
	}
	else throw ExMatrix(wrongSize, size);
}

// Перегрузка операции вычитания двух матриц
Matrix Matrix::operator-(const Matrix& m) {
	if (size == m.size) {
		Matrix res;
		res.Create(size);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.ar[i][j] = ar[i][j] - m.ar[i][j];
		return res;
	}
	else throw ExMatrix(wrongSize, size);
}

// Перегрузка операции индексации
int* Matrix::operator[](int ind) {
	if (ind >= 0 && ind < size)
		return ar[ind];
	else
		throw ExMatrix(outOfAr, size);
}

// Вывод в поток
ostream& operator<<(ostream& out, const Matrix& m) {
	out << endl;
	for (int i = 0; i < m.size; ++i) {
		for (int j = 0; j < m.size; ++j)
			out << m.ar[i][j] << " ";
		out << endl;
	}
	return out;
}

// Ввод в поток
istream& operator>>(istream& in, const Matrix& m) {
	for (int i = 0; i < m.size; ++i)
		for (int j = 0; j < m.size; ++j)
			in >> m.ar[i][j];
	return in;
}

// Транспонирование
Matrix Matrix::Trans() {
	Matrix res;
	res.Create(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.ar[i][j] = ar[j][i];
	return res;
}

// Проверка обладает ли матрица диагональным преобладанием
bool Matrix::Diag() {
	int sum = 0;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (i != j)
				sum += abs(ar[i][j]);
	for (int i = 0; i < size; ++i) {
		if (ar[i][i] >= sum)
			return true;
		else return false;
	}
}

// Умножение матрицы на число
Matrix operator*(const Matrix& m, int k) {
	Matrix res;
	res.Create(m.size);
	for (int i = 0; i < m.size; ++i)
		for (int j = 0; j < m.size; ++j)
			res.ar[i][j] = m.ar[i][j] * k;
	return res;
}

// Умножение числа на матрицу
Matrix operator*(int k, const Matrix& m) {
	Matrix res;
	res.Create(m.size);
	for (int i = 0; i < m.size; ++i)
		for (int j = 0; j < m.size; ++j)
			res.ar[i][j] = m.ar[i][j] * k;
	return res;
}

// Умножение матриц
Matrix operator*(const Matrix& m1, const Matrix& m2) {
	if (m1.size == m2.size) {
		Matrix res;
		res.Create(m1.size);
		for (int i = 0; i < m1.size; ++i)
			for (int j = 0; j < m1.size; ++j) {
				int sum = 0;
				for (int k = 0; k < m1.size; ++k)
					sum += m1.ar[i][k] * m2.ar[k][j];
				res.ar[i][j] = sum;
			}
		return res;
	}
	else throw ExMatrix(wrongSize, m1.size);
}