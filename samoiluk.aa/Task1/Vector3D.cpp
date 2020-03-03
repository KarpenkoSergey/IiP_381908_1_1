#include <clocale>
#include <iostream>
#include <math.h>
#include "Vector3D.h"
using namespace std;

// Конструктор по умолчанию
Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

// Перегрузка операции присваивания
Vector3D& Vector3D::operator=(const Vector3D& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

// Перегрузка операции сложения векторов
Vector3D Vector3D::operator + (const Vector3D& vec) {
	Vector3D res;
	res.x = x + vec.x;
	res.y = y + vec.y;
	res.z = z + vec.z;
	return res;
}

// Перегрузка операции вычитания векторов
Vector3D Vector3D::operator - (const Vector3D& vec) {
	Vector3D res;
	res.x = x - vec.x;
	res.y = y - vec.y;
	res.z = z - vec.z;
	return res;
}

// Перегузка операции умножения вектора на число
Vector3D operator *(double scal, const Vector3D& vec) {
	Vector3D res;
	res.x = scal * vec.x;
	res.y = scal * vec.y;
	res.z = scal * vec.z;
	return res;
}

// Перегузка операции скалярного произведения векторов
double operator *(const Vector3D& vec1, const Vector3D& vec2) {
	Vector3D res;
	double mlt;
	res.x = vec1.x * vec2.x;
	res.y = vec1.y * vec2.y;
	res.z = vec1.z * vec2.z;
	mlt = res.x + res.y + res.z;
	return mlt;
}

// Перегрузка операций сранения вектоов по длине
bool Vector3D::operator ==(const Vector3D& vec) {
	return sqrt(x * x + y * y + z * z) == sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

bool Vector3D::operator >(const Vector3D& vec) {
	return sqrt(x * x + y * y + z * z) > sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

bool Vector3D::operator <(const Vector3D& vec) {
	return sqrt(x * x + y * y + z * z) < sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

// Вывод в поток
ostream& operator << (ostream& out, const Vector3D& vec) {
	out << "x=" << vec.x << " " << "y=" << vec.y << " " << "z=" << vec.z;
	return out;
}

// Ввод в поток
istream& operator >> (istream& in, Vector3D& vec) {
	cout << "x=";
	in >> vec.x;
	cout << "y=";
	in >> vec.y;
	cout << "z=";
	in >> vec.z;
	return in;
}