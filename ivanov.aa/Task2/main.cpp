#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <clocale>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	Matrix c1, c2(5), c3(3, 123), c4(c3), c5; // Проверка конструкторов
	std::cout << c1 << std::endl << c2 << std::endl << c3 << std::endl <<  c4 << std::endl; // Проверка вывода

	std::cin >> c4; // Проверка ввода в поток 
	std::cout << c4; 

	if (c4.DiagPreob()) // Проверка диагонального преобладания 
		std::cout << "c4 обладает диагональным преобладанием\n";

	c4.Transpos(); // Проверка транспонирования
	std::cout << c4;

	c4 = c3 - c4; // Проврека вычитания
	std::cout << c4;

	c4 =  -1 * (c4 - c3); // Проверка умножения на скаляр
	std::cout << c4;
	c3 = c4;

	c4 = c4 + c4; // Проверка сложения
	std::cout << c4;

	c4 = c3 * c4; // Проверка умножения
	std::cout << c4;

	std::ofstream strOut; // Проверка вывода в файл
	strOut.open("file.txt");
	strOut << c4;
	strOut.close();

	std::ifstream strIn; // Проверка ввода из файла
	strIn.open("file.txt");
	strIn >> c5;
	std::cout << c5;
	strIn.close();
}