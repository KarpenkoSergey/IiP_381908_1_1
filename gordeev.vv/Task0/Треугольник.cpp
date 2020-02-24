#include <iostream>
#include <clocale>
using namespace std;

int vichislenia(double x, double y, double z)
{
	double s;
	double cosmax;
	s = sqrt((x + y + z) * (x + y) * (x + z) * (y + z));
	if (x < y)
		if (z <= y)
			cosmax = 1 - (s / (x * z));
		else
			cosmax = 1 - (s / (x * y));
	if(x>y)
		if(z<=x)
			cosmax = 1 - (s / (y * z));
		else
			cosmax = 1 - (s / (x * y));
	return cosmax;

}


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

	do
	{
		std::cout << "Введите стороны треугольника";
		std::cin >> a >> b >> c;
	} while (proverka(a, b, c));
	rez = vichislenia(a, b, c);
	if (rez > 0)
		std::cout << "Треугольник остроугольный" << std::endl;
	if (rez == 0)
		std::cout << "Треугольник прямоугольный" << std::endl;
	if (rez < 0)
		std::cout << "Треугольник тупоугольный" << std::endl;
	return 0;
}


