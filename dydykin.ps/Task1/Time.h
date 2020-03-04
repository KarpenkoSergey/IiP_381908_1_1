#pragma once
#include <iostream>
using namespace std;
class Time {
private:
	int hou, min, sec;
public:
	Time();
	Time(const Time& t);
	Time(string s);
	Time(int _hou, int _min, int _sec);
	~Time();
	string ToString();
	Time operator + (const Time& t);
	Time operator - (const Time& t);
	Time& operator = (const Time& t);
	bool operator == (const Time& t);
	bool operator > (const Time& t);
	bool operator < (const Time& t);
	friend ostream& operator << (ostream&, const Time& t);
	friend istream& operator >> (istream&, Time& t);
};
