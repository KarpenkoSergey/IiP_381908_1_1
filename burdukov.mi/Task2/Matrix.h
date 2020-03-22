#pragma once

class Matrix
{
private:
	int size;
	int** matrix;

public:
	//конструкторы и деконструкторы 

	Matrix();
	Matrix(int n);
	Matrix(int n, int k);
	Matrix(const Matrix& c);
	~Matrix();
	//функции
	friend Matrix Transposition(const Matrix& c);
	friend bool CheckDiag(const Matrix& c);

	//перегрузки
	Matrix& operator=(const Matrix& a);
	Matrix operator+(const Matrix& a);
	friend std::istream& operator>> (std::istream& in, Matrix& c);
	friend std::ostream& operator<< (std::ostream& out, const Matrix& c);
	Matrix operator*(const Matrix& c);
	Matrix operator*(int k);
	Matrix operator*=(const Matrix& c);
	Matrix operator*=(int k);
	int* operator[](const int index);
};

