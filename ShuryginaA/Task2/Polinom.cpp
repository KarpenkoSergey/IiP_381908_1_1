#include <iostream>
#include<clocale>
#include <fstream>
#include <algorithm>
#include "Polinom.h"
using namespace std;

Exception::Exception(ExceptionType _error)
{
	error = _error;
}

Polinom::Polinom()
{
	deg = 0;
	cft=new double[1];
	cft[0] = 0.0;
}

Polinom::Polinom(const Polinom& c)
{
	if(c.deg<1)
		throw Exception(ExceptionType::UnacceptableDeg);
	else 
	{
		deg = c.deg;
		cft = new double[(double)deg + 1];
		for (int i = 0;i <= deg;++i)
			cft[i] = c.cft[i];
	}
}

Polinom::Polinom(int _deg, double* _cft)
{
	if (_deg < 1)
		throw Exception(ExceptionType::UnacceptableDeg);
	else
	{
		deg = _deg;
		cft = new double[(double)deg + 1];

		for (int i = 0;i <= deg;i++)
			cft[i] = _cft[i];
	}
}

Polinom::Polinom(int _deg)
{
	if (_deg < 1)
		throw Exception(ExceptionType::UnacceptableDeg);
	else
	{
		deg = (unsigned int)_deg;
		for (int i = 0;i <= _deg;++i)
			cft[i] = 1;
	}

}

Polinom::~Polinom()
{
	deg = 0;
	delete[] cft;
}

Polinom Polinom::operator = (const Polinom& c)
{

		deg = c.deg;
		delete[] cft;
		cft = new double[(double)deg + 1];
		for (int i = 0;i <= deg;i++)
			cft[i] = c.cft[i];
		return *this;
	
}

double& Polinom::operator[](int ind)
{
	if (ind > deg || ind<0)
		throw Exception(ExceptionType::outOfBoundsArray);
	else 
		return cft[ind];

}

const double& Polinom::operator[](int ind) const 
{
	if (ind > deg || ind < 0)
		throw Exception(ExceptionType::outOfBoundsArray);
	else
		return cft[ind];

}


Polinom Polinom ::operator+ (const Polinom& c)
{

		Polinom res;
		int i;
		int maxd = max(deg, c.deg);
		int mind = min(deg, c.deg);
		res.deg = maxd;
		res.cft = new double[(double)maxd + 1];
		for (i = 0;i <= mind;++i)
			res.cft[i] = cft[i] + c.cft[i];
		if (maxd == deg)
			for (i + 1;i <= res.deg;++i)
				res.cft[i] = cft[i];
		else if (maxd == c.deg)
			res.cft[i] = c.cft[i];



		return res;
	
}

double Polinom::value(Polinom c, double x)
{

		double ans = 0;
		for (int i = 0;i <= c.deg;i++)
			ans += c.cft[i] * pow(x, i);

		return ans;
	
}



 void Polinom::derv(Polinom& _c)
{
	

		 _c.deg = deg - 1;
		 _c.cft = new double[deg];
		 for (int i = 0;i <= deg - 1;i++)
			 _c.cft[i] = cft[i + 1] * ((double)i + 1);
	 
 
 }

 

void Polinom::OutputPolinom()
{
	for (int i = deg;i > 0;i--)
	{
		if(cft[i-1]>=0)
			cout << cft[i] << "x^" << i << "+";
		else
			cout << cft[i] << "x^" << i;

	}
	cout << cft[0]<<endl;

}

std::ostream& operator<<(std::ostream& stream, Polinom& p)
{
	stream << p.deg<<" ";
	for (int i = 0;i <= p.deg;++i)
		stream << p.cft[i]<<" ";
	stream << endl;
	return stream;

}

std::istream& operator>>(std::istream& stream, Polinom& p)
{
	stream >> p.deg;
	p.cft = new double[(double)p.deg + 1];
	for (int i = 0; i <= p.deg; i++)
		stream >> p.cft[i];
	return stream;

}

