#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int _size){
	size = _size;
	m = new int* [size];
	for (int i = 0; i < size; ++i) {
		m[i] = new int[size];
	}
}
Matrix::Matrix() {
	size = 0;
	m = 0;
}
Matrix::Matrix(const Matrix& mat) {
	size = mat.size;
	m = new int* [size];
	for (int i = 0; i < size; ++i) {
		m[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			m[i][j] = mat.m[i][j];
}
Matrix::Matrix(int _size, int k) {
	size = _size;
	m = new int* [size];
	for (int i = 0; i < size; ++i) {
		m[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			m[i][j] = k;
}
Matrix::~Matrix() {
	for (int i = 0; i < size; ++i)
		delete[] m[i];
	delete[] m;
	size = 0;
}
Matrix& Matrix::operator=(const Matrix& mat) {
	size = mat.size;
	m = new int* [size];
	for (int i = 0; i < size; ++i) {
		m[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			m[i][j] = mat.m[i][j];
	return *this;
}
Matrix Matrix::operator+(const Matrix& mat) {
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.m[i][j] = m[i][j] + mat.m[i][j];
	return res;
}
Matrix Matrix::operator-(const Matrix& mat) {
	Matrix res(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res.m[i][j] = m[i][j] - mat.m[i][j];
	return res;
}
int* Matrix::operator[](int i) {
 	if( i >= 0 && i < size )
        return m[i];
}
ostream& operator << (ostream& out,const Matrix& mat) {
	for (int i = 0; i < mat.size; ++i) {
		for (int j = 0; j < mat.size; ++j)
			out << mat.m[i][j] << " ";
		out << endl;
	}
	return out;
}
istream& operator >> (istream& in, Matrix& mat) {
	for (int i = 0; i < mat.size; ++i)
		for (int j = 0; j < mat.size; ++j)
			in >> mat.m[i][j];
	return in;
}
void trsp(const Matrix& mat) {
	for (int i = 0; i < mat.size; ++i)
		for (int j = i; j < mat.size; ++j)
			swap(mat.m[i][j],mat.m[j][i]);
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
	Matrix res(size);
	for (int i=0; i<size; ++i)
		for (int j = 0; j < size; ++j) {
			res.m[i][j] = 0;
			for (int k = 0; k < size; ++k)
				res.m[i][j] += m[i][k] * mat.m[k][j];
		}
	return res;
}