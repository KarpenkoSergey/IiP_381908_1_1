#include <iostream>
#include"Money.h"
#include <fstream>
#include<string>
using namespace std;
Money::Money() {
	rub = 0;
	cop = 0;
}
Money::~Money() {
	rub = 0;
	cop = 0;
}
bool Money::operator<(const Money& c) {
	return rub * 100 + cop < c.rub * 100 + c.cop;
}
bool Money::operator>(const Money& c) {
	return rub * 100 + cop > c.rub * 100 + c.cop;
}
bool Money::operator==(const Money& c) {
	return rub * 100 + cop == c.rub * 100 + c.cop;
}
Money Money::out(const std::string& filename) const {
	std::fstream file;
	file.open(filename, std::fstream::out);
	if (file.is_open()) {
		file << *this;
	}
	else {
		throw std::invalid_argument("Can not open file: " + filename);
	}
}
Money Money::in(const std::string& filename) {
	std::fstream file;
	file.open(filename, std::ostream::in);
	if (file.is_open()) {
		file >> *this;
	}
	else {
		throw std::invalid_argument("Can not open file: " + filename);
	}
}

Money Money::operator-(const Money& c) {
	Money res;
	res.rub = rub - c.rub;
	res.cop = cop - c.cop;
	if (res.cop < 0)
	{
		res.rub--;
		res.cop += 100;
	}
	return res;
}
Money Money::operator/(double c) {
	Money res;
	if (c == 0)
	{
		res = 0;
		return res;
	}
	res.cop = cop;
	if (rub > 0) {
		while (rub > 0)
		{
			rub = rub - 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop / c;
		while (res.cop > 99)
		{
			res.rub++;
			res.cop = res.cop - 100;
		}
	}
	else {
		while (rub < 0)
		{
			rub = rub + 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop / c;
		while (res.cop > 99)
		{
			res.rub--;
			res.cop = res.cop - 100;
		}
	}
	return res;
}

Money::Money(int _rub, int _cop) {
	rub = _rub;
	cop = _cop;
	if (_cop > 99)
	{
		rub += cop / 100;
		cop %= 100;
	}
}

Money& Money::operator=(const Money& c) {
	rub = c.rub;
	cop = c.cop;
	return *this;
}

Money Money::operator+(const Money& c) {
	Money res;
	res.rub = rub + c.rub;
	res.cop = cop + c.cop;
	while (res.cop > 99)
	{
		res.rub++;
		res.cop = res.cop - 100;
	}
	return res;
}
Money Money::operator*(double c) {
	Money res;
	res.cop = cop;
	if (rub > 0) {
		while (rub > 0)
		{
			rub = rub - 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop * c;
		while (res.cop > 99)
		{
			res.rub++;
			res.cop = res.cop - 100;
		}
	}
	else {
		while (rub < 0)
		{
			rub = rub + 1;
			res.cop = res.cop + 100;
		}
		res.cop = res.cop * c;
		while (res.cop > 99)
		{
			res.rub--;
			res.cop = res.cop - 100;
		}
	}
	return res;
}



Money::Money(int d) {
	rub = d;
	cop = 0;
}


Money::Money(const Money& c) {
	rub = c.rub;
	cop = c.cop;
}

void Money::output() {
	cout << rub << "." << cop;
}

ostream& operator<<(ostream& stream, const Money& c) {

	stream << c.rub << "." << c.cop;

	return stream;

}

istream& operator>>(istream& stream, Money& c) {

	stream >> c.rub >> c.cop;

	return stream;

}