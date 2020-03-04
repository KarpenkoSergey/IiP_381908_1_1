#include "Time.h"
#include <locale>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Time t1, t3(23, 14, 53), t4("12:43:50"), t5(t3), t6(12, 30, 30), t7(13, 6, 8);
	string str1 = t3.TimeToString();
	std::cout << "�������� ��������� - (������ ���� 0:0:0) " << t6 - t6;
	std::cout << "�������� ��������� + (������ ���� 1:1:0) " << t6 + t6;
	std::cout << "�������� ������ �������������� ������ � ������ (������ ���� 23:14:53): " << str1 << endl;
	std::cout << "�������� ������������ �������������� ����� (������ ���� 12:43:50): " << t4;
	std::cout << "�������� ������������ �� ��������� (������ ���� 0:0:0) " << t1;
	std::cout << "�������� ������������ ����������� (������ ���� 23:14:53): " << t5;
	std::cout << "�������� ������������-�������������� (������ ���� 12:30:30): " << t6;
	t1 = t7;
	std::cout << "�������� ��������� = (������ ���� 13:6:8): " << t7;
	t7.TinPut();
	t7.ToutPut("t4");
	bool tf;
	tf = t4 > t6;
	std::cout << "�������� ��������� > (������ ���� 1): " << tf << endl;
	tf = t4 < t6;
	std::cout << "�������� ��������� < (������ ���� 0): " << tf << endl;
	tf = t4 >= t6;
	std::cout << "�������� ��������� >= (������ ���� 1): " << tf << endl;
	tf = t4 <= t6;
	std::cout << "�������� ��������� <= (������ ���� 0): " << tf << endl;
	tf = t4 == t4;
	std::cout << "�������� ��������� == (������ ���� 1): " << tf << endl;
	tf = t4 != t4;
	std::cout << "�������� ��������� != (������ ���� 0): " << tf << endl;
	return 0;
}