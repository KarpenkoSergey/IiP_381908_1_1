#include <iostream>
#include <fstream>
#include"Matrix.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	ofstream out("OutputMatrix.txt");
	ifstream in("InputMatrix.txt");

	try {
		Matrix m1(3, 5), m2(m1);
		m1[0][0] = 6;
		m2[2][1] = 22;
		cout << m1 << endl << m2 << endl;
		Matrix m3 = m1 + m2;
		Matrix m4 = m1 - m2;
		cout << m3 << endl << m4 << endl;
		m3 = m3.trsp();
		cout << m3 << endl << m3.diag_dm() << endl;
		m3 = m3 * 10;
		m4 = m3 * m1;
		cout << m3 << endl;
		out << m4;
		Matrix m5(4);
		in >> m5;
		cout << m5 << endl;
		m5 = m3 * 3;
		cout << m5 << endl;
		Matrix m6(5);
		cout << m6 * m5;
		out << m6 * m5;
	}
	catch (Exception error) {
		switch (error.err)
		{
		case ExceptionType::outArray:
			cout << "Ошибка! Выход за границу массива \n";
			out << "-1\n";
			break;
		case ExceptionType::sizeError:
			cout << "Ошибка! Размеры матриц различны \n";
			out << "-2\n";
			break;
		}
	}
	in.close();
	out.close();
}  