#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Введите сторону a: ";
	int a = 0;
	cin >> a;

	cout << "Введите сторону b: ";
	int b = 0;
	cin >> b;

	cout << "Введите сторону c: ";
	int c = 0;
	cin >> c;

	if (a * a + b * b == c * c)
		cout << "Треугольник прямоугольный";
	if (a * a + b * b > c * c)
		cout << "Треугольник остроуголный";
	if (a * a + b * b < c * c)
		cout << "Треугольник тупоугольный";
	return 0;
}