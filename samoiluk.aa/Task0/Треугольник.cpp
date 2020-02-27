#include <clocale>
#include <iostream>

using namespace std;

void triangle(int ta, int tb, int tc) // Функция для определения вида треугольника
{
	if (ta > tb + tc)
		cout << "Треугольник не существует";
	else
		if ((ta * ta) == (tb * tb + tc * tc))
			cout << "Прямоугольный треугольник";
		else
			if ((ta * ta) > (tb * tb + tc * tc))
				cout << "Тупоугольный треугольник";
			else
				cout << "Остроугольный треугольник";
}

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int a, b, c; // Стороны треугольника

	cout << "Введите значения сторон тругольника в порядке убывания: ";
	cin >> a >> b >> c;

	triangle(a, b, c);

	return 0;
}