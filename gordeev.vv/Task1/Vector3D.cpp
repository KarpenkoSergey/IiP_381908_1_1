#include "Vector3D.h"
#include <iostream>
#include <math.h>
using namespace std;
Vector3D ::Vector3D(void)
{
	x = 0; y = 0; z = 0;
}
Vector3D::Vector3D(double d)
{
	x = d;
	y = 0;
	z = 0;
}
Vector3D Vector3D :: operator=(const Vector3D& C)
{
	x = C.x; y = C.y; z = C.z;
	return *this;
}
Vector3D Vector3D ::operator+(const Vector3D& C)
{
	Vector3D res;
	res.x = x + C.x;
	res.y = y + C.y;
	res.z = z + C.z;
	return res;
}

Vector3D Vector3D ::operator-(const Vector3D& C)
{
	Vector3D res;
	res.x = x - C.x;
	res.y = y - C.y;
	res.z = z - C.z;
	return res;
}
//Скалярное произведение векторов
double  Vector3D ::sclprvect(const Vector3D& C)
{
	double res;
	res = x * C.x + y * C.y + z * C.z;
	return res;
}
//
Vector3D Vector3D::umnnachislo(int m)
{
	Vector3D res;
	res.x = x * m;
	res.y = y * m;
	res.z = z * m;
	return res;
}
Vector3D Vector3D ::sravnenie(const Vector3D& C)
{
	if(sqrt(x*x+y*y+z*z)>sqrt(C.x*C.x+C.y*C.y+C.z*C.z))
		cout << "1 вектор больше 2 "<< endl;
	else
		cout << "2 вектор больше 1" << endl;
	return C;
}
ostream& operator<<(ostream& stream, const Vector3D& C)
{
	stream << C.x << endl;

	stream << C.y << endl;

	stream << C.z << endl;
	return stream;
}
istream& operator>> (istream& stream, Vector3D& C)
{
	stream >> C.x;
	stream >> C.y;
	stream >> C.z;
	return stream;
}
