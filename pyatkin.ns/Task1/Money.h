#pragma once
#include <iostream>

using namespace std;

class Money {
public:
	Money();
	Money(int _rub, int _cop);
	Money(const Money& c);
	Money(int d);
	~Money();
	Money operator +(const Money& c);
	void output();
	Money& operator = (const Money& c);
	bool operator==(const Money& c);
	bool operator>(const Money& c);
	bool operator<(const Money& c);
	Money operator-(const Money& c);
	Money operator/(double c);
	Money operator*(double c);
	friend ostream& operator<<(ostream& stream, const Money& c);
	friend istream& operator>>(istream& stream, Money& c);
	friend bool operator==(const Money& left, const Money& right) {
		if (left.rub == right.rub && left.cop == right.cop)
		{
			return true;
		}
		return false;
	}
private:
	int rub;
	int cop;

};