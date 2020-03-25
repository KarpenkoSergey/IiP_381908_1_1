#pragma once
using namespace std;

enum ExceptionType { wrongSize, outOfAr };
struct ExMatrix {
	ExceptionType type;
	int incSize;
	ExMatrix(ExceptionType _type, int _incSize) {
		type = _type;
		incSize = _incSize;
	}
};

class Matrix {
private:
	int size;
	int** ar;
public:
	void Create(int size); // Выделение памяти
	Matrix(); // Конструктор по умолчанию
	Matrix(int _size);
	Matrix(const Matrix& m); // Копирование
	Matrix(int _size, int fill); // Инициализатор
	~Matrix(); // Деструктор
	Matrix& operator=(const Matrix& m); // Перегрузка операции присваивания
	Matrix operator+(const Matrix& m); // Перегрузка операции сложения матриц
	Matrix operator-(const Matrix& m); // Перегрузка операции вычитания двух матриц
	int* operator[](int ind); // Перегрузка операции индексации
	friend ostream& operator<<(ostream&, const Matrix& m); // Вывод в поток
	friend istream& operator>>(istream&, const Matrix& m); // Ввод в поток
	Matrix Trans(); // Транспонирование
	bool Diag(); // Проверка обладает ли матрица диагональным преобладанием
	friend Matrix operator*(const Matrix& m, int k);// Умножение матрицы на число
	friend Matrix operator*(int k, const Matrix& m); // Умножение числа на матрицу
	friend Matrix operator*(const Matrix& m1, const Matrix& m2); // Умножение матриц
};