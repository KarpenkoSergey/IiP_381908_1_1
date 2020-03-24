#include <iostream>
#include "Matrix.h"

Exception::Exception(ExceptionType _err) {
	err = _err;
}

void del(Matrix& mat) {
	if (mat.size > 0) {
		for (int i = 0; i < mat.size; ++i)
			delete[] mat.m[i];
		delete[] mat.m;
	}
}

void make(Matrix& mat, int _size) {
	mat.size = _size;
	mat.m = new int* [mat.size];
	for (int i = 0; i < mat.size; ++i) {
		mat.m[i] = new int[mat.size];
	}
}
Matrix::Matrix(int _size){
	make(*this, _size);
}
Matrix::Matrix() {
	size = 0;
	m = 0;
}

Matrix::Matrix(const Matrix& mat) {
	make(*this, mat.size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			m[i][j] = mat.m[i][j];
}
Matrix::Matrix(int _size, int k) {
	make(*this, _size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			m[i][j] = k;
}
Matrix::~Matrix() {
	m = 0;
	size = 0;
}
Matrix& Matrix::operator=(const Matrix& mat) {
	if (size != mat.size) {
		if (size > 0)
			del(*this);
		make(*this, mat.size);
	}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			m[i][j] = mat.m[i][j];
	return *this;
}
Matrix Matrix::operator+(const Matrix& mat) {
	Matrix res(size);
	if (size == mat.size) {
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.m[i][j] = m[i][j] + mat.m[i][j];
	}
	else
		throw Exception(ExceptionType::sizeError);
	return res;
}
Matrix Matrix::operator-(const Matrix& mat) {
	Matrix res(size);
	if (size == mat.size) {
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				res.m[i][j] = m[i][j] - mat.m[i][j];
	}
	else
		throw Exception(ExceptionType::sizeError);
	return res;
}
int* Matrix::operator[](int i) {
	if (i >= 0 && i < size)
		return m[i];
	else
		throw Exception(ExceptionType::outArray);
}
ostream& operator << (ostream& out,const Matrix& mat) {
	out << mat.size << endl;
	for (int i = 0; i < mat.size; ++i) {
		for (int j = 0; j < mat.size; ++j)
			out << mat.m[i][j] << " ";
		out << endl;
	}
	return out;
}
istream& operator >> (istream& in, Matrix& mat) {
	in >> mat.size;
	for (int i = 0; i < mat.size; ++i)
		for (int j = 0; j < mat.size; ++j)
			in >> mat.m[i][j];
	return in;
}
Matrix trsp(const Matrix& mat) {
	Matrix res(mat.size);
	for (int i = 0; i < res.size; ++i)
		for (int j = 0; j < res.size; ++j)
			res.m[i][j] = mat.m[j][i];
	return res;
}
bool diag_dm(const Matrix& mat) {
	int s = 0;
	int flag = 0;
	for (int i = 0; i < mat.size; ++i) {
		for (int j = 0; j < mat.size; ++j)
			if (i != j)
				s += abs(mat.m[i][j]);
		if (s > mat.m[i][i])
			return 0;
		if (s < mat.m[i][i])
			flag = 1;
		s = 0;
	}
	return flag;
}
Matrix Matrix::operator*(int k) {
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.m[i][j] = m[i][j] * k;
	return res;
}
Matrix Matrix::operator*(const Matrix& mat) {
	if (size == mat.size) {
		Matrix res(size);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j) {
				res.m[i][j] = 0;
				for (int k = 0; k < size; ++k)
					res.m[i][j] += m[i][k] * mat.m[k][j];
			}
		return res;
	}
	else
		throw Exception(ExceptionType::sizeError);
}
Matrix operator*(const Matrix& mat, int k) {
	return mat * k;
}