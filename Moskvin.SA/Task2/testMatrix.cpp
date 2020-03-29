#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include "Matrix.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n = 0;
	cin >> n;

	int** a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 1 + rand() % 10;
		}
	}

	Matrix m, m0, m1(n), m2(n, a), m3(m1);

	cout << "Матрица 1: \n" << m1; // проверка вывода в поток
	cout << endl;
	cout << "Матрица 2: \n" << m2;

	m = m1 + m2; // проверка сложения
	cout << endl;
	cout << "Сумма матрицы 1 и 2 = \n" << m;
	cout << endl;

	m0 = 5 * m1 * m2; // проверка умножения
	cout << "Произведение матрицы 1 и 2 на 5 = \n" << m0;
	cout << endl;

	cout << "Транспонированная матрица суммы 1 и 2:\n" << m.T(); // проверка транспонирования
	cout << endl;
	cout << "Транспонированная матрица произведения 1, 2 и 5:\n" << m0.T();
	cout << endl;

	if (m1.DiagPreob())
		cout << "Матрица 1 имеет диагональное преобладание\n";
	else
		cout << "Матрица 1 не имеет диагональное преобладание\n";

	ofstream os; // запись в файл
	os.open("Matrix.txt");
	os << m1 << m2;
	os.close();

	ifstream is; // чтение из файла
	is.open("Matrix.txt");
	Matrix r(n), t(n);
	is >> r >> t;
	cout << "\n" << r << "\n" << t;
	is.close();

	return 0;
}