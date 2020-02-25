#include <iostream>
#include<clocale>
using namespace std;

class Rational 
{
	int num;
	int dem;
public:
	Rational();                 // Конструктор по умолчанию
	Rational(const Rational& c);// Конструктор копирования
	Rational(int _num, int _dem);// Конструктор инициализации
	// type convertion
	~Rational();   // Деструктор
	void input();
	void output();
	void check(int n, int d);

};
Rational::Rational()
{
	num = 0;
	dem = 1;
}

Rational::Rational(const Rational& c)
{
	num = c.num;
	dem = c.dem;
}

Rational::Rational(int _num, int _dem)
{
	num = _num;
	dem = _dem;
}
 
Rational::~Rational()
{
	num = 0;
	dem = 1;
}
int main()