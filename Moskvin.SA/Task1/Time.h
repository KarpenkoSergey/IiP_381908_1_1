#pragma once
#include <iostream>
#include <fstream>

class Time
{
private:
	int hou, min, sec;
public:
	Time();
	Time(int _hou, int _min, int _sec);
	Time(std::string time);
	~Time();
	std::string TextTime();
	Time operator + (const Time& t);
	Time operator - (const Time& t);
	Time& operator = (const Time& t);
	bool operator < (const Time& t);
	bool operator > (const Time& t);
	bool operator <= (const Time& t);
	bool operator >= (const Time& t);
	bool operator == (const Time& t);
	friend std::ostream& operator << (std::ostream& stream, Time& t);
	friend std::istream& operator >> (std::istream& stream, Time& t);
};

std::ostream& operator << (std::ostream& stream, Time& t);
std::istream& operator >> (std::istream& stream, Time& t);