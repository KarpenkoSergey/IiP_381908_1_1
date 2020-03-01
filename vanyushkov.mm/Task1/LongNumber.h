﻿#pragma once
#include <iostream>

typedef unsigned int uint; // Беззнаковое целое (int)

class LongNumber
{
private:
	char* number;  // Используется только для ввода числа через std::cin >>
	int high_part; // Старшая часть числа
	uint low_part; // Младшая часть числа
	int sign;      // Знак числа (1 или -1 -> '+' или '-')

public:
	// Конструктор по умолчанию
	LongNumber();

	// Конструктор копирования
	LongNumber(const LongNumber& num);

	// Конструктор преобразования типа
	LongNumber(const long long& num);

	// Деструктор
	~LongNumber();

	// Модуль числа
	void Abs(const LongNumber& num);

	// Сложение чисел
	LongNumber Add(const LongNumber& num);

	// Разность чисел
	LongNumber Sub(const LongNumber& num);

	// Произведение чисел
	LongNumber Mul(const LongNumber& num);

	// Частное числе
	LongNumber Div(const LongNumber& num);

	// Остаток от деления
	LongNumber Mod(const LongNumber& num);

	// Перегрузка операций ------------------------------------------

	// Оператор присваивания
	LongNumber& operator= (const LongNumber& num);

	// Оператор сложения
	LongNumber operator+ (const LongNumber& num);

	// Оператор разности
	LongNumber operator- (const LongNumber& num);

	// Оператор умножения
	LongNumber operator* (const LongNumber& num);

	// Оператор деления
	LongNumber operator/ (const LongNumber& num);

	// Операотор остатка от деления
	LongNumber operator% (const LongNumber& num);

	// Оператор сложения с присваиванием
	LongNumber& operator+= (const LongNumber& num);

	// Операторо вычитания с присваиванием
	LongNumber& operator-= (const LongNumber& num);

	// Оператор умножения с присваиванием
	LongNumber& operator*= (const LongNumber& num);

	// Оператор деления с присваиванием
	LongNumber& operator/= (const LongNumber& num);

	// Оператор остатка от деления с присваиванием
	LongNumber& operator%= (const LongNumber& num);

	// Префикс суммы
	LongNumber& operator++ ();

	// Постфикс суммы
	LongNumber& operator++ (int);

	// Префикс разности
	LongNumber& operator-- ();

	// Постфикс разности
	LongNumber& operator-- (int);

	// Унарный минус
	LongNumber operator- ();

	// Оператор не
	bool operator! ();

	// Оператор равенства
	bool operator== (const LongNumber& num);

	// Оператор неравенства
	bool operator!= (const LongNumber& num);

	// Оператор больше
	bool operator> (const LongNumber& num);

	// Оператор больше или равно
	bool operator>= (const LongNumber& num);

	// Оператор меньше
	bool operator< (const LongNumber& num);

	// Оператор меньше или равно
	bool operator<= (const LongNumber& num);

	// Вывод на консоль через std::cout <<
	friend std::ostream& operator<< (std::ostream& stream, const LongNumber& num);

	// Ввод числа через консоль через std::cin >>
	friend std::istream& operator>> (std::istream& stream, LongNumber& num);
};