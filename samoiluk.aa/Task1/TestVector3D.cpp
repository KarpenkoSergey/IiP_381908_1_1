#include <clocale>
#include <iostream>
#include "Vector3D.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Vector3D vector1, vector2, vector3, vector4, vectorAdd, vectorSubt, vectorMlt;
	double scalar;
	double scalMlt;

	cout << "Введите координаты векторов:\n";
	cout << "Вектор 1: ";
	cin >> vector1;
	cout << "Вектор 2: ";
	cin >> vector2;
	cout << "Введите число: ";
	cin >> scalar;

	vectorAdd = vector1 + vector2; // Сложение векторов
	vectorSubt = vector1 - vector2; // Вычитание векторов
	scalMlt = vector1 * vector2; // Скалярное произведение векторов
	vectorMlt = scalar * vector1; // Умножение вектора на число

	// Сравнение длин векторов
	if (vector1 == vector2)
		cout << "Векторы равны по длине" << endl;

	if (vector1 > vector2)
		cout << "Длина первого вектора больше длины второго" << endl;

	if (vector1 < vector2)
		cout << "Длина первого вектора меньше длины второго" << endl;

	cout << "Вектор сумма: " << vectorAdd << endl;
	cout << "Вектор разность: " << vectorSubt << endl;
	cout << "Скалярное произведение: " << scalMlt << endl;
	cout << "Умножение вектора на число: " << vectorMlt << endl;
}