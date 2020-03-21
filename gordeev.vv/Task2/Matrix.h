#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
class Matrix
{
private:
	int size;
	int**mtx;	
public:
	Matrix();//Конструктор по умолчанию	
	Matrix(int _size);//Конструктор инициализатор 1
	Matrix(int _size,int fill);//Конструктор инициализатор 2
	Matrix(const Matrix& matrix);//Конструктор копирования
	~Matrix();//Деструктор
	Matrix operator=(const Matrix& matrix);
	Matrix operator+(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);//Умножение матриц
	Matrix operator*(const int num);//Умножение матрицы на число
	friend Matrix operator* (const int num, Matrix& matrix);//Умножение числа на матрицу
	int* operator[](int i);//Индексация
   void Transpositione();
   bool DiagonalDominant();
   friend istream& operator>>(istream& stream, Matrix& matrix);
   friend ostream& operator<<(ostream& stream, const Matrix& matrix);
};

