#include "Vector3D.h"
#include <iostream>
#include <math.h>
using namespace std;
//Конструктор по умолчанию
Vector3D ::Vector3D(void)
{
	x = 0; y = 0; z = 0;
}
//Конструктор преобразования типа
Vector3D::Vector3D(double d)
{
	x = d;
	y = 0;
	z = 0;
}
//Конструктор инициализатор
Vector3D::Vector3D(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}
//Конструктор копирования
Vector3D::Vector3D(const Vector3D& C)
{
	x = C.x;
	y = C.y;
	z = C.z;
}
//Деструктор
Vector3D::~Vector3D()
{
	x = 0; y = 0; z = 0;
}
//Перегрузка оператора =
Vector3D Vector3D :: operator=(const Vector3D& C)
{
	x = C.x; y = C.y; z = C.z;
	return *this;
}
//Перегрузка оператора +
Vector3D Vector3D ::operator+(const Vector3D& C)
{
	Vector3D res;
	res.x = x + C.x;
	res.y = y + C.y;
	res.z = z + C.z;
	return res;
}
//Перегрузка оператора -
Vector3D Vector3D ::operator-(const Vector3D& C)
{
	Vector3D res;
	res.x = x - C.x;
	res.y = y - C.y;
	res.z = z - C.z;
	return res;
}

//Перегрузка операции скалярного произведения векторов
double  Vector3D ::sclprvect(const Vector3D& C)
{
	double res;
	res = x * C.x + y * C.y + z * C.z;
	return res;
}
//Перегрузка операции умножения вектора на число
Vector3D Vector3D::umnnachislo(int m)
{
	Vector3D res;
	res.x = x * m;
	res.y = y * m;
	res.z = z * m;
	return res;
}
//Перегрузка операции сравнения двух векторов
Vector3D Vector3D ::sravnenie(const Vector3D& C)
{
	if(sqrt(x*x+y*y+z*z)>sqrt(C.x*C.x+C.y*C.y+C.z*C.z))
		cout << "1 вектор больше 2 "<< endl;
	else
		cout << "2 вектор больше 1" << endl;
	return C;
}
//Перегрузка оператора <<
ostream& operator<<(ostream& stream, const Vector3D& C)
{
	stream << C.x << " " << C.y << " " << C.z << " " << endl;
	return stream;
}
//Перегрузка оператора >>
istream& operator>> (istream& stream, Vector3D& C)
{
	stream >> C.x;
	stream >> C.y;
	stream >> C.z;
	return stream;
}
