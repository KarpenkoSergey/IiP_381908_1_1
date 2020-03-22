#include<iostream>
#include"Matrix.h"
#include<Locale.h>

int main() {
	setlocale(LC_CTYPE, "Russian");
	Matrix a(2, 3);
	Matrix b(2, 2);
	try {
		Matrix c = a + b;
		std::cout << "Сложение Матриц " << c << std::endl;
		c *= 5;
		std::cout << "Умножение на скаляр:" << c;
		c = a;
		std::cout << "Диагональное преобладание " << CheckDiag(c) << std::endl;
		std::cin >> c;
		c = Transposition(c);
		std::cout << "Транспонирование матрицы " << c << std::endl;
		
		b *= a;
		std::cout << a;
	}
	catch (int error) {
		std::cout << "ERROR: ";
		if (error == 1) std::cout << "size of matrix not equal" << std::endl;
		if (error == 2) std::cout << "Index of Matrix out of range";
	}
}
