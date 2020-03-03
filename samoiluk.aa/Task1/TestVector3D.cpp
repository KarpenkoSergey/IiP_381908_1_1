#include <clocale>
#include <iostream>
#include "Vector3D.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Vector3D vector1, vector2, vectorAdd, vectorSubt, vectorMlt;
	double scalar;
	double scalMlt;

	cout << "������� ���������� ��������:\n";
	cout << "������ 1: ";
	cin >> vector1;
	cout << "������ 2: ";
	cin >> vector2;
	cout << "������� �����: ";
	cin >> scalar;

	vectorAdd = vector1 + vector2; // �������� ��������
	vectorSubt = vector1 - vector2; // ��������� ��������
	scalMlt = vector1 * vector2; // ��������� ������������ ��������
	vectorMlt = scalar * vector1; // ��������� ������� �� �����

	// ��������� ���� ��������
	if (vector1 == vector2)
		cout << "������� ����� �� �����" << endl;

	if (vector1 > vector2)
		cout << "����� ������� ������� ������ ����� �������" << endl;

	if (vector1 < vector2)
		cout << "����� ������� ������� ������ ����� �������" << endl;

	cout << "������ �����: " << vectorAdd << endl;
	cout << "������ ��������: " << vectorSubt << endl;
	cout << "��������� ������������: " << scalMlt << endl;
	cout << "��������� ������� �� �����: " << vectorMlt << endl;

	return 0;
}