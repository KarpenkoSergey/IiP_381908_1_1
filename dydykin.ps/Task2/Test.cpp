#include <iostream>
#include <fstream>
#include"Matrix.h"
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	ofstream out("MatrixOut.txt");
	ifstream in("MatrixIn.txt");
	try
	{
		Matrix m1(2, 5), m2(m1);
		m1[1][1] = 3;
		cout << m1 << endl << m2 << endl;
		Matrix m3 = m1 + m2;
		Matrix m4 = m1 - m2;
		cout << m3 << endl << m4 << endl;
		m4.Transposition();
		cout << m4 << endl << m4.CheckDiag() << endl;
		m3 = m3 * 3;
		m4 = m3 * m1;
		cout << m3 << endl;
		out << m4;
		Matrix m5(4);
		in >> m5;
		cout << m5 << endl;
		m5 = m3 * 2;
		cout << m5 << endl;
		Matrix m6(5);
		cout << m6 * m5;
		out << m6 * m5;
	}
	catch (int error)
	{
		cout << "ERROR:";
		if (error == 1) cout << "Size of Matrix not equal";
		if (error == 2) cout << "Index of Matrix out of range";
	}
}