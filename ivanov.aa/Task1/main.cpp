#include "Time.h"
#include <iostream>
#include <clocale>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Time c1, c2(13425), c3("143:42:1"), c4(21, 45, 2); // Инициализвация
	c1.TimeOut(); // Проверки инициализации
	c2.TimeOut();
	c3.TimeOut();
	c4.TimeOut();

	c1 = c4; // Проврека присваивания и потокового вывода
	std::cout << c1;

	std::cin >> c1; // Проверка потокового ввода

	c4 = c3 + c1; // Проверка сложения для Time + Time
	std::cout << c4;

	c4 = c4 + 14; // Проверка сложения для Time + int
	c4.TimeOut();

	c1 = c4 - c3; // Проверка вычитания для Time - Time
	c1.TimeOut();

	std::cout << std::endl << c1 << c2; // Проверка bool функции 
	if (c1 > c2)
		std::cout << "Время с1 > с2";
	else
		std::cout << "Время с1 <= c2";
}