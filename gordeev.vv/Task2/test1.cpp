#include "Matrix.h"
#include <iostream>
#include<locale.h>
#include <math.h>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	Matrix m1(4, 2), m2(m1),m3(4);		
	cout << m1 << endl << m2 << endl;
	m3 = m1;
	cout << m3 << endl;
	m1[1][2] = 4;
	m2[0][2] = 7;
	m3 = (m2 + m1);
	m3[1][1] = 67;
	m3[2][2] = 89;
	m3[3][3] = 97;
	cout << m3 << endl;
	m2 = m3;
	m3.Transpositione();
	cout << m3 << endl;
	m3.DiagonalDominant() ? cout << "Yes" : cout << "No";
	cout << endl;
	cout << endl;
	cout << m2 * 7 << endl;
	cout << m2 * m1 << endl;	
    ofstream strOut("test.txt");
	strOut << m1;
	strOut.close();
	Matrix l(3);
	ifstream strIn("test.txt");
	strIn >> l;
	strIn.close();
	cout << l;
}