#include <iostream>
#include <fstream>
#include"Matrix.h"
using namespace std;

int main() {
	Matrix m1(3, 5), m2(m1);
	m1[0][0] = 6;
	m2[2][1] = 22;
	cout << m1 << endl << m2 << endl;
	Matrix m3 = m1 + m2;
	Matrix m4 = m1 - m2;
	cout << m3 << endl << m4 << endl;
	trsp(m3);
	cout << m3 << endl << diag_dm(m3) << endl;
	m3 = m3 * 10;
	m4 = m3 * m1;
	cout << m3 << endl;
	ofstream out("Matrix.txt");
	out << m4;
	out.close();
	Matrix m5(3);
	ifstream in("Matrix.txt");
	in >> m5;
	in.close();
	cout << m5 << endl;
}