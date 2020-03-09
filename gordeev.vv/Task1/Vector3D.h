#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Vector3D
{
public:
	double x, y, z;
public:
	Vector3D(void);
	Vector3D(double d);
	Vector3D(const Vector3D&C);
	Vector3D(double _x, double _y, double _z);
   ~Vector3D();
	Vector3D operator=(const Vector3D& C);
	Vector3D operator+(const Vector3D& C);
	double sclprvect(const Vector3D& C);
	Vector3D operator-(const Vector3D& C);
	Vector3D umnnachislo(int m);
	Vector3D sravnenie(const Vector3D& C);
	friend istream & operator>>(istream & stream, Vector3D& C);
	friend ostream & operator<<(ostream & stream, const Vector3D& C);
	
	
};
