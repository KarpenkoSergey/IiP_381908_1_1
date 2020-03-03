#pragma once
using namespace std;

class Vector3D {
private:
	double x;
	double y;
	double z;
public:
	Vector3D(); // ����������� �� ���������
	Vector3D& operator = (const Vector3D& vec); // ���������� �������� ������������
	Vector3D operator + (const Vector3D& vec); // ���������� �������� �������� ��������
	Vector3D operator - (const Vector3D& vec); // ���������� �������� ��������� ��������
	friend Vector3D operator *(double scal, const Vector3D& vec); // ��������� �������� ��������� ������� �� �����
	friend double operator * (const Vector3D& vec1, const Vector3D& vec2); // ��������� �������� ���������� ������������ ��������
	// ���������� �������� �������� ������� �� �����
	bool operator ==(const Vector3D& vec);
	bool operator >(const Vector3D& vec);
	bool operator <(const Vector3D& vec);
	friend ostream& operator << (ostream&, const Vector3D& vec); // ����� � �����
	friend istream& operator >> (istream&, Vector3D& vec); // ���� � �����
};