#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

//ввод целочисленной переменной с контролем
int inputInt(const char name[], int left, int right)
{
	int res;
	do
	{
		printf(name);
		printf("= (от %d до %d) = ", left, right);
		scanf_s("%d", &res);
	} while (res<left || res > right);
	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, sum;
	cout << "введите стороны треугольника" << endl;
	a = inputInt("a", 0, 1000);
	b = inputInt("b", 0, 1000);
	c = inputInt("c", 0, 1000);
	sum = a + b;
	if (c > sum)
	{
		cout << "такого треугольника не существует" << endl;
		return 0;
	}
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	sum = a * a + b * b;
	c = c * c;
	if (c > sum)
	{
		cout << "треугольник тупоугольный";
	}
	else
	{
		if (c < sum)
		{
			cout << "треугольник остроугольный";
		}
		else
		{
			cout << "треугольник прямоугольный";
		}
	}
	return 0;
}