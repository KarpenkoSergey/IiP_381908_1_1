#pragma once
#include <iostream>
#include <cstdlib>
#include <locale>
using namespace std;

class Time
{
private:
	int hou, min, sec;
public:
	Time();
	Time(const Time& t);
	Time(string t);
	Time(int h, int m, int s);
	~Time();
	string TimeToString();
	Time& operator=(const Time& c);
	Time operator+(const Time& c);
	Time perepol();
	Time operator-(const Time& c);
	bool operator>(const Time& c);
	bool operator<(const Time& c);
	bool operator==(const Time& c);
	bool operator>=(const Time& c);
	bool operator<=(const Time& c);
	bool operator!=(const Time& c);
	friend ostream& operator<<(ostream& ostream, const Time& c);
	friend istream& operator>>(istream& istream, Time& c);
	//в задании не было этого, но на всякий случай
	void TinPut();
	void ToutPut(const char* name);
	int getHour();
	int getMin();
	int getSec();
	void setHour(int _hou);
	void setMin(int _min);
	void setSec(int _sec);
	void setTime(int _hou, int _min, int _sec);
};
