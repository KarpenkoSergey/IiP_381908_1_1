#include <iostream> 
#include <clocale>
#include <fstream>
#include <algorithm>
#include <stdio.h> 
#include "Polinom.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	std::ofstream fout("Pol.txt");
	std::ifstream fin("Pol.txt");
	try
	{

		double arr1[] = { 1,2,3,2 };
		Polinom p1(3, arr1);

		double c1 = p1.value(p1, 2); // значение в точке
		cout << c1 << endl;
		p1.OutputPolinom();

		Polinom p2;
		p1.derv(p2);                 // производная
		p2.OutputPolinom();

		Polinom p3;
		p3 = p1 + p2;
		p3.OutputPolinom();

		double arr[] = { 1,2,3,4 };
		Polinom p4(3, arr);

		fout << p2;
		fin >> p4;

		p4.OutputPolinom();



	}
	catch (Exception error)
	{

		switch (error.error)
		{
		case ExceptionType::outOfBoundsArray:
			std::cout << std::endl << "Ошибка.Выход за границы массива \n";
			fout << "-1 \n";
			break;
		case ExceptionType::UnacceptableDeg:
			std::cout << std::endl << " Недопустимая степень полинома \n";
			fout << "-2 \n";
			break;

		}

		fin.close();
		fout.close();

		return 0;

	}
}