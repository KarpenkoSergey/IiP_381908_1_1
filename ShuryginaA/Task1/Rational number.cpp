#include <iostream>
#include<clocale>
#include <fstream>
#include "RatNum.h"
using namespace std;

Rational::Rational()
{
	n = 0;
	m = 1;
}

Rational::Rational(const Rational& c)
{
	n = c.n;
	m = c.m;
}

Rational::Rational(int _num, int _dem)
{
	n = _num;
	m = _dem;
}

Rational::Rational(int _n)
{
	n = _n;
	m = 1;
}

Rational::~Rational()
{
	n = 0;
	m = 1;
}

void Rational::input()
{
	cout << "n = ";

	cin >> n;
	cout << "m = ";
	cin >> m;
	while (m == 0)
	{
		cout << "Некорректная дробь: нулевой знаменатель" << endl;
		cout << "n = ";
		cin >> n;
		cout << "m = ";
		cin >> m;
	} 
	  
	check();
}
void Rational::output(const char* name)
{
	cout << name << n << "/ " << m << endl;

}

void Rational::check()
{
	if (n == m)
	{
		n = 1;
		m = 1;
	}
	else
	{
		int i = 2;
		while (i <= n && i <= m)
		{
			if (n % i == 0 && m % i == 0)
			{
				n /= i;
				m /= i;
				i--;
			}
			i++;
		}
	}
}

Rational& Rational::operator =(const Rational& c)
{
	(*this).n = c.n; m = c.m;

	return *this;
}


Rational Rational::operator*(const Rational& c)
{
	Rational res;
	res.n = n * c.n;
	res.m = m * c.m;
	res.check();
	

	return res;
}

Rational Rational::operator/(const Rational& c)
{
	Rational res;
	res.n = n * c.m;
	res.m = m * c.n;
	res.check();

	return res;

}

Rational Rational::operator+(const Rational& c)
{
	Rational res;
	res.m = m * c.m;
	res.n = (res.m / m) * n + (res.m / c.m) * c.n;
	res.check();
	
	return res;

}


Rational Rational::operator-(const Rational& c)
{
	Rational res;
	res.m = m * c.m;
	res.n = (res.m / m) * n - (res.m / c.m) * c.n;
	res.check();

	return res;

}




bool Rational::operator==(const Rational& c)
{
	bool res;
	res = (n == c.n) && (m == c.m);
	return res;
}

bool Rational::operator>(const Rational& c)
{
	int dem = m * c.m;
	int num1 = (dem / m) * n;
	int num2=(dem / c.m)* c.n;
	return num1 > num2;

}

bool Rational::operator<(const Rational& c)
{
	int dem = m * c.m;
	int num1 = (dem / m) * n;
	int num2 = (dem / c.m) * c.n;
	return num1 < num2;

}


