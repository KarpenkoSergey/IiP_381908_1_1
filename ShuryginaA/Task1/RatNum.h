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
	~Rational();                 // Деструктор
	void input();                // ввод дроби с контролем знаменателя
	void output(const char* name);// вывод дроби
	void check();                // проверка дроби на сократимость

	Rational& operator =(const Rational& c);
	Rational operator*(const Rational& c);
	Rational operator/(const Rational& c);
	Rational operator+ (const Rational& c);
	Rational operator- (const Rational& c);
	bool operator==(const Rational& c);
	bool operator>(const Rational& c);
	bool operator<(const Rational& c);
	friend std::ostream& operator<< (std::ostream& out, const Rational& point);
	friend std::istream& operator>> (std::istream& in, Rational& point);
	
};

