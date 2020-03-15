﻿#include "Time.h"
#include <iostream>
#include <clocale>
#include <fstream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Time c1, c2(15386), c3("143:42:1"), c4(21, 45, 2); // Инициализвация
	std::ofstream strOut;
	strOut.open("file.txt");
	c1.TimeOut(); // Проверки инициализации
	c2.TimeOut();
	c3.TimeOut();
	c4.TimeOut();
	std::cout << std::endl << c2.TimeToString() << std::endl; // Проверка перевода в строку
	c2 = c2 * 5; // Проверка умножения на целое число
	c2.TimeOut();
	c2 = c2 / 5; // Проверка деления на целове число
	c2.TimeOut();

	c1 = c4; // Проврека присваивания и потокового вывода
	std::cout << c1;

	std::cin >> c1; // Проверка потокового ввода

	c4 = c3 + c1; // Проверка сложения для Time + Time
	std::cout << c4;

	c4 = c4 + 4568; // Проверка сложения для Time + int
	c4.TimeOut();

	c1 = c4 - c3; // Проверка вычитания для Time - Time
	c1.TimeOut();

	std::cout << std::endl << c1 << c2; // Проверка bool функции 
	if (c1 > c2)
		std::cout << "Время с1 > с2\n\n";
	else
		std::cout << "Время с1 <= c2\n\n";

	c1 = c1 + 5124;
	strOut << c1; // Проверка вывода в файл
	strOut.close();

	std::ifstream strIn;
	strIn.open("file.txt");
	Time c5;
	strIn >> c5; // Проверка ввода в файл
	std::cout << c5; 
	strIn.close();

}