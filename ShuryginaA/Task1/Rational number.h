#pragma once

class Rational
{
	int n;
	int m;
public:
	Rational();                 // Конструктор по умолчанию
	Rational(const Rational& c);// Конструктор копирования
	Rational(int _num, int _dem);// Конструктор инициализации
	Rational(int _n);             // конструктор преобразования типа
	~Rational();                  // Деструктор
	void output(const char* name);// вывод дроби
	void check(int _n, int _m);

};
