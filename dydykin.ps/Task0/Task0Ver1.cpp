#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;//стороны треугольника
	cin >> a >> b >> c;//считывание сторон треугольника
	//воспользуемся правилом из геометрии для определения вида треугольника
	if (c * c < a * a + b * b)
		cout << "Треугольник остроугольный";
	if (c * c > a * a + b * b)
		cout << "Треугольник тупоугольный";
	if (c * c == a * a + b * b)
		cout << "Треугольник прямоугольный";
	return 0;
}