#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <clocale>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	Matrix c1, c2(5), c3(3, 123), c4(c3), c5; // �������� �������������
	std::cout << c1 << std::endl << c2 << std::endl << c3 << std::endl <<  c4 << std::endl; // �������� ������

	std::cin >> c4; // �������� ����� � ����� 
	std::cout << c4; 

	if (c4.DiagPreob()) // �������� ������������� ������������ 
		std::cout << "c4 �������� ������������ �������������\n";

	c4.Transpos(); // �������� ����������������
	std::cout << c4;

	c4 = c3 - c4; // �������� ���������
	std::cout << c4;

	c4 =  -1 * (c4 - c3); // �������� ��������� �� ������
	std::cout << c4;
	c3 = c4;

	c4 = c4 + c4; // �������� ��������
	std::cout << c4;

	c4 = c3 * c4; // �������� ���������
	std::cout << c4;

	std::ofstream strOut; // �������� ������ � ����
	strOut.open("file.txt");
	strOut << c4;
	strOut.close();

	std::ifstream strIn; // �������� ����� �� �����
	strIn.open("file.txt");
	strIn >> c5;
	std::cout << c5;
	strIn.close();
}