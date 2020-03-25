#include <clocale>
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Matrix.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	ofstream fOut("file.txt");
	ifstream fIn("file.txt");
	int flag = 1;

	while (flag)
	{
		try
		{
			int flag = 1;
			int n1; // Размер матрицы 1
			int n2; // Размер матрицы 2
			int num;


			cout << "Введите размер матрицы 1: ";
			cin >> n1;
			cout << "Введите размер матрицы 2: ";
			cin >> n2;
			cout << "Введите число: ";
			cin >> num;

			Matrix mat1(n1), mat2(n2), mat3(n1, 5), mat4(mat2), matAdd1(n1), matAdd2(n1), matSubt(n2), matTrans(n1), matNum(n1), matMlt(n1);

			cout << "Матрица 1: " << mat1 << endl;
			cout << "Матрица 2: " << mat2 << endl;
			cout << "Матрица 3: " << mat3 << endl;
			cout << "Матрица 4: " << mat4 << endl;


			matAdd1 = mat1 + mat3;
			matAdd2 = mat1 + mat2;
			matSubt = mat2 - mat4;
			matTrans = mat1.Trans();
			matNum = matAdd1 * num;
			matMlt = mat1 * mat3;

			cout << "Cумма матриц: " << matAdd1 << endl;
			cout << "Разность матриц: " << matSubt << endl;
			cout << "Транспонированная матрица: " << matTrans << endl;
			cout << "Произведение матрицы на число: " << matNum << endl;
			cout << "Произведение матриц: " << matMlt << endl;

			if (mat1.Diag())
				cout << "Матрица обладает диагональным преобладанием." << endl;
			else cout << "Матрица не обладает диагональным преобладанием." << endl;

			matAdd1[1][1] = 100;

			fOut << matAdd1 << endl;
			fIn >> matAdd1;
			cout << matAdd1; // Проверка чтения из файла
			flag = 0;
		}
		catch (ExMatrix exp)
		{
			switch (exp.type)
			{
			case (wrongSize):
				cout << "Матрицы разного размера" << endl;
				flag = 1;
				break;
			case (outOfAr):
				cout << "Выход за границы массива" << endl;
				flag = 1;
				break;
			}
		}
	}
	fOut.close();
	fIn.close();

	return 0;
}