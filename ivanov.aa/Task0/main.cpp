#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

//__________________________________Ввод вещественного числа с контролем
double input_float(const char str[], double l, double r)
{
	double n; // Объявление возвращаемой переменной 
	cout << "Введите " << str << endl;
	cin >> n; // Ввод первичного значения 
	while (n<l || n>r) // Проверка на случай ошибочно введенных данных
	{
		cout << "Введенное число должно быть в значении от " << l << " до " << r << endl << "Введите число заново: ";
		cin >> n;
	}
	cout << endl;
	return n; // Возвращаем n
}
double max (double a, double b)
{
	if (a >= b)
		return a;
	else
		return b;
}
double min (double a, double b)
{
	if (a <= b)
		return a;
	else
		return b;
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите стороны треугольника:" << endl;
	float a = input_float("a", 0.0, 10000.0), b = input_float("b", 0.0, 10000.0), c = input_float("c", 0.0, 10000.0), a_, b_, c_;
	if (a < 0.00001 || b < 0.00001 || c < 0.00001)
	{
		cout << "Такого треугольника не существует";
		return 0;
	}
	a_ = max(a, max(b, c)); // Находим большую сторону
	b_ = min(a, min(b, c)); // Находим меньшую сторону 
	c_ = a + b + c - a_ - b_; // Находим среднюю сторону
	if (a_ >= b_ + c_)
	{
		cout << "Такого треугольника не существует";
		return 0;
	}
	if (a_ * a_ < (b_ * b_ + c_ * c_))
		cout << "Треугольник остроугольный";
	else if (fabs((a_ * a_) - (b_ * b_ + c_ * c_)) < 0.0001)
		cout << "Треугольник прямоугольный";
	else
		cout << "Треугольник тупоугольный";
	return 0;
}