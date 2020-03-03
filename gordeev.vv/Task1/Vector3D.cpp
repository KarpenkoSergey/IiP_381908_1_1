#include "Vector3D.h"
#include <iostream>
#include <math.h>
using namespace std;
Vector3D ::Vector3D(void)
{
	x = 0; y = 0; z = 0;
}
Vector3D Vector3D :: operator=(const Vector3D& C)
{
	x = C.x; y = C.y; z = C.z;
	return C;
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

Vector3D  Vector3D ::operator*(const Vector3D& C)
{
	Vector3D res;
	res.x = x * C.x;
	res.y = y * C.y;
	res.z = z * C.z;
	return res;
}
Vector3D Vector3D::sclumn(int m)
{
	Vector3D res;
	res.x = x * m;
	res.y = y * m;
	res.z = z * m;
	return res;
}
Vector3D Vector3D ::sravnenie(const Vector3D& C)
{
	if (sqrt(x ^ 2 + y ^ 2 + z ^ 2) > sqrt((C.x) ^ 2 + (C.y) ^ 2 + (C.z) ^ 2))
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