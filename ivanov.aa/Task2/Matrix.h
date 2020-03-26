#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
/*
6. Матрица
Разработать класс Matrix.
Класс должен хранить квадратную матрицу целых чисел заданного размера.
Класс должен содержать все необходимые конструкторы, деструктор
Класс должен предоставлять следующие операции и методы :
1) операцию присваивания
2) операцию суммирования двух матриц одинакового размера
3) операцию индексации с контролем выхода индекса за границы массива.De
4) операции << и >> для сохранения себя в файле и чтения из файла
5) операцию транспонирования матрицы
6) проверить, обладает ли матрица диагональным преобладанием,
7) операцию умножения матриц и операцию умножения скаляра на матрицу */ 

class Matrix
{
	private:
		int dim;
		int** matr;
		void MemFree(void); // Операция освобождения динамической памяти
		void MemSet(const int _dim); // Операция выделения динамической памяти для матрицы
		void ZeroSet(void); // Операция обнуления элементов массива на случай ошибки размерности при вычислениях 
	public:
		//Конструкторы
		Matrix(); // Конструктор по умолчанию
		Matrix(const Matrix& c); // Конструктор копирования
		Matrix(int _dim); // Конструктор инициализатор
		Matrix(int _dim, int zap);  // Конструктор инициализатор

		//Деструктор
		~Matrix();

		//Методы
		void Transpos(void); // Транспонирование
		bool DiagPreob(); // Проверка матрицы на диагональное преобладание
		
		//Перегрузки
		Matrix& operator= (const Matrix& c); // Перегрузка присваивания
		Matrix operator+ (const Matrix& c); // Перегрузка сложения для того же класса
		Matrix operator- (const Matrix& c); // Перегрузка вычитания для того же класса
		Matrix operator* (const Matrix& c); // Перегрузка умножения матрицы на матрицу
		Matrix operator* (const int ch);
		friend Matrix operator* (const int ch, const Matrix& c);

		int*& operator[] (int index);
		
		friend std::ofstream& operator<< (std::ofstream& out, Matrix& c); // Перегрузка вывода в файл
		friend std::ifstream& operator>> (std::ifstream& in, Matrix& c); // Перегрузка ввода в файл

		friend std::ostream& operator<< (std::ostream& out, const Matrix& c); // Перегрузка <<
		friend std::istream& operator>> (std::istream& in, Matrix& c); // Перегрузка >>
};
#endif