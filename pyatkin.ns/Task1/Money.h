#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money {
public:
	Money();
	Money(int _rub, int _cop);
	Money(const Money& c);
	Money(int d);
	~Money();
	Money out(const std::string& filename) const;
	Money in(const std::string& filename);
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
private:
	int rub;
	int cop;

};