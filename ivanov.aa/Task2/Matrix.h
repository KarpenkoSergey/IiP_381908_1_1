#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
/*
6. �������
����������� ����� Matrix.
����� ������ ������� ���������� ������� ����� ����� ��������� �������.
����� ������ ��������� ��� ����������� ������������, ����������
����� ������ ������������� ��������� �������� � ������ :
1) �������� ������������
2) �������� ������������ ���� ������ ����������� �������
3) �������� ���������� � ��������� ������ ������� �� ������� �������.De
4) �������� << � >> ��� ���������� ���� � ����� � ������ �� �����
5) �������� ���������������� �������
6) ���������, �������� �� ������� ������������ �������������,
7) �������� ��������� ������ � �������� ��������� ������� �� ������� */ 

class Matrix
{
	private:
		int dim;
		int** matr;
		void MemFree(void); // �������� ������������ ������������ ������
		void MemSet(const int _dim); // �������� ��������� ������������ ������ ��� �������
		void ZeroSet(void); // �������� ��������� ��������� ������� �� ������ ������ ����������� ��� ����������� 
	public:
		//������������
		Matrix(); // ����������� �� ���������
		Matrix(const Matrix& c); // ����������� �����������
		Matrix(int _dim); // ����������� �������������
		Matrix(int _dim, int zap);  // ����������� �������������

		//����������
		~Matrix();

		//������
		void Transpos(void); // ����������������
		bool DiagPreob(); // �������� ������� �� ������������ ������������
		
		//����������
		Matrix& operator= (const Matrix& c); // ���������� ������������
		Matrix operator+ (const Matrix& c); // ���������� �������� ��� ���� �� ������
		Matrix operator- (const Matrix& c); // ���������� ��������� ��� ���� �� ������
		Matrix operator* (const Matrix& c); // ���������� ��������� ������� �� �������
		Matrix operator* (const int ch);
		friend Matrix operator* (const int ch, const Matrix& c);

		int*& operator[] (int index);
		
		friend std::ofstream& operator<< (std::ofstream& out, Matrix& c); // ���������� ������ � ����
		friend std::ifstream& operator>> (std::ifstream& in, Matrix& c); // ���������� ����� � ����

		friend std::ostream& operator<< (std::ostream& out, const Matrix& c); // ���������� <<
		friend std::istream& operator>> (std::istream& in, Matrix& c); // ���������� >>
};
#endif