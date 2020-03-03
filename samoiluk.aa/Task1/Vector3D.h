#pragma once
using namespace std;

class Vector3D {
private:
	double x;
	double y;
	double z;
public:
	Vector3D(); // Конструктор по умолчанию
	Vector3D& operator = (const Vector3D& vec); // Перегрузка операции присваивания
	Vector3D operator + (const Vector3D& vec); // Перегрузка операции сложения векторов
	Vector3D operator - (const Vector3D& vec); // Перегрузка операции вычитания векторов
	friend Vector3D operator *(double scal, const Vector3D& vec); // Перегузка операции умножения вектора на число
	friend double operator * (const Vector3D& vec1, const Vector3D& vec2); // Перегузка операции скалярного произведения векторов
	// Перегрузка операций сранения вектоов по длине
	bool operator ==(const Vector3D& vec);
	bool operator >(const Vector3D& vec);
	bool operator <(const Vector3D& vec);
	friend ostream& operator << (ostream&, const Vector3D& vec); // Вывод в поток
	friend istream& operator >> (istream&, Vector3D& vec); // Ввод в поток
};