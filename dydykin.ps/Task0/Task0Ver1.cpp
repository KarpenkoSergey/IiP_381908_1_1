#include <iostream>
#include <clocale>
using namespace std;
void typeoftriangle(int x1, int x2, int x3)//������� ��� ����������� ���� ������������ + �������� �� ��� �������������
{
	if ((x1 > x2 + x3) || (x2 > x1 + x3) || (x3 > x1 + x2))
		cout << "����������� �� ����������";
	else if (x1*x1==x2*x2+x3*x3)
		cout << "����������� �������������";
		else if (x1 * x1 > x2 * x2 + x3 * x3)
			cout << "����������� ������������";
			else cout << "����������� �������������";
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;//������� ������������
	cout << "���������� ������ ������� ������������ � ������� �������� ";
	cin >> a >> b >> c;
	typeoftriangle(a, b, c);
	return 0;
}