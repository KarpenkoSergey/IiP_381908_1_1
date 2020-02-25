//Подключение необходимых библиотек
#include <iostream>
#include <clocale>
using namespace ::std;
int check(double x, double y, double z) //Функция, проверяющая существование треугольника
{
	if ((x < y + z) && (y < x + z) && (z < x + y))
		return 1;
	else
	{
		cout << "Такого треугольника не существует." << endl;
		return 0;
	}
}
int cos(double x, double y, double z)//Функция, определяющая знак косинуса угла
{
	//Используем теорему косинусов
	double cos = (y * y + z * z - x * x) / (2 * y * z);
	if (cos > 0)
		return 1;
	else
	{
		if (cos == 0)
			return 0;
		else return -1;
	}
}
void triangle(double x, double y, double z) //Функция, определяющая тип треугольника
{
	int X = cos(x, y, z);
	int Y = cos(y, x, z);
	int Z = cos(z, x, y);
	if ((X < 0) || (Y < 0) || (Z < 0))
		cout << "Тупоугольный";
	else
	{
		if (!X || !Y || !Z)
			cout << "Прямоугольный";
		else cout << "Остроугольный";
	}

}
int main()
{
	setlocale(LC_CTYPE, "rus"); //Подключение кириллицы
	double a, b, c;
	//Цикл. Пользователь не выйдет из него, пока не введет допустимые значения сторон
	do {
		cout << "Введите длины сторон: ";
		cin >> a >> b >> c;
	} while (!check(a, b, c));
	triangle(a, b, c);
	return 0;
}