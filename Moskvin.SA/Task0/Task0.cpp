#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "������� ������� a: ";
	int a = 0;
	cin >> a;

	cout << "������� ������� b: ";
	int b = 0;
	cin >> b;

	cout << "������� ������� c: ";
	int c = 0;
	cin >> c;

	if (a * a + b * b == c * c)
		cout << "����������� �������������";
	if (a * a + b * b > c * c)
		cout << "����������� ������������";
	if (a * a + b * b < c * c)
		cout << "����������� ������������";
	return 0;
}