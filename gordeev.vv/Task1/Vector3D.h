#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Vector3D
{
public:
	int x, y, z;
public:
	Vector3D(void);
	Vector3D operator=(const Vector3D& C);
	Vector3D operator+(const Vector3D& C);
	Vector3D operator*(const Vector3D& C);
	Vector3D operator-(const Vector3D& C);
	Vector3D sclumn(int m);
	Vector3D sravnenie(const Vector3D& C);
	friend istream & operator>>(istream & stream, Vector3D& C);
	friend ostream & operator<<(ostream & stream, const Vector3D& C);
	
	
};
