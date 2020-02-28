#include <iostream>
#include <clocale>
using namespace std;
void typeoftriangle(int x1, int x2, int x3)//функция для определения вида треугольника + проверка на его существование
{
	if ((x1 > x2 + x3) || (x2 > x1 + x3) || (x3 > x1 + x2))
		cout << "Треугольник не существует";
	else if (x1*x1==x2*x2+x3*x3)
		cout << "Треугольник прямоугольный";
		else if (x1 * x1 > x2 * x2 + x3 * x3)
			cout << "Треугольник тупоугольный";
			else cout << "Треугольник остроугольный";
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;//стороны треугольника
	cout << "Необходимо ввести стороны треугольника в порядке убывания ";
	cin >> a >> b >> c;
	typeoftriangle(a, b, c);
	return 0;
}