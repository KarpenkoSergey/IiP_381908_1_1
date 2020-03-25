#include <iostream>
#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <clocale>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	try
	{
		Matrix m1(3, 1), m2(m1);
		cout << m1 << endl << m2 << endl;
		Matrix m3(3);
		m3 = m1;
		cout << m3 << endl;
		m1[1][2] = 4; m2[0][2] = 7;
		m3 = m2 + m1;
		m3[0][0] = 10;
		m3[1][1] = 15;
		m3[2][2] = 13;
		cout << m3 << endl;
		m2 = m3;
		m1 = m3.transpose();
		cout << m1 << endl;
		m3.diagonallyDominant() ? cout << "Yes" : cout << "No";
		cout << endl << endl;
		cout << m2 * m3 << endl;
		cout << m2 * 3 << endl;
		std::ofstream strOut("Matrix.txt");
		strOut << m3;
		strOut.close();
		Matrix n(3);
		std::ifstream strIn("Matrix.txt");
		strIn >> n;
		strIn.close();
		cout << n;
	}
	catch (Exception err)
	{
		switch (err.error)
		{
		case ExceptionType::outOfBoundsMatrix:
			std::cout << std::endl << "Индексация за пределы матрицы! \n";
			break;
		case ExceptionType::sizeError:
			std::cout << std::endl << "Разные размеры матриц! \n";
			break;
		}
	}
}