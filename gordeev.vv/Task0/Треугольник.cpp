#include <iostream>
#include <clocale>
using namespace std;
//Вычисление косинуса наибольшего угла треугольника
double vichislenia(double x, double y, double z)
{
	double cosmax = 0;
	if (x < y)
	{
		if (z <= y)
			cosmax = (x * x + z * z - y * y) / (2 * z * x);
		if (z > y)
			cosmax = (x * x - z * z + y * y) / (2 * y * x);
	}
	if (x > y) {
		if (z <= x)
			cosmax = (-x * x + z * z + y * y) / (2 * z * y);
		if (z > x)
			cosmax = (x * x - z * z + y * y) / (2 * y * x);
	}

	if (x = y) {
		if (z >= x)
			cosmax = (x * x - z * z + y * y) / (2 * y * x);
		if (z < x)
			cosmax = (x * x + z * z - y * y) / (2 * z * x);
	}
	return cosmax;

}

//Проверка треугольника на существование
int proverka(double x, double y, double z)
{
	if ((x < y + z) && (y < x + z) && (z < x + y))
		return 1;
	else
	{
		std::cout << std::endl << "Некорректно введены стороны" << std::endl;
		return 0;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b, c;
	double rez;
	//Ввод сторон треугольника
	do
	{
		std::cout << "Введите стороны треугольника: " << std::endl;
		std::cin >> a >> b >> c;
	} while (!proverka(a, b, c));
	rez = vichislenia(a, b, c);
	//В зависимости от косинуса наибольшего угла выводится тип треугольника
	if (rez > 0)
		std::cout << "Треугольник остроугольный" << std::endl;
	if (rez == 0)
		std::cout << "Треугольник прямоугольный" << std::endl;
	if (rez < 0)
		std::cout << "Треугольник тупоугольный" << std::endl;
	return 0;
}


