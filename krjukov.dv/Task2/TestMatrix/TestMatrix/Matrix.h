#pragma once
#include <iostream>
enum class ExceptionType {sizeError, outOfBoundsMatrix};
struct Exception
{
	ExceptionType error;
	Exception(ExceptionType _error);
};
class Matrix
{
private:
	int size;
	int** mat;
public:
	Matrix();
	Matrix(int _size);
	Matrix(int _size, int fill);
	Matrix(const Matrix& m);
	~Matrix();
	Matrix& operator=(const Matrix& m);
	Matrix operator+(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix operator*(int num);
	friend Matrix operator* (int num, Matrix& m);
	int* operator[](int _i);
	Matrix transpose();
	bool diagonallyDominant();
	friend std::ostream& operator<< (std::ostream& stream, const Matrix& m);
	friend std::istream& operator>> (std::istream& stream, Matrix& m);
	void create(int _size);
	void del();
};
std::ostream& operator<< (std::ostream& stream, const Matrix& t);
std::istream& operator>> (std::istream& stream, Matrix& t);



