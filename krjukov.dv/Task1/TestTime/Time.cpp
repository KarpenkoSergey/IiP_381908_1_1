#include "Time.h"
#include <iostream>
#include <fstream>
Time::Time()
{
	hou = 0; min = 0;  sec = 0;
}
Time::Time(const Time &t)
{
	hou = t.hou; min = t.min; sec = t.sec;
}
Time::Time(int _hou, int _min, int _sec)
{
	hou = _hou; min = _min; sec = _sec;
}
Time::Time(const char* c)
{
	hou = 0; min = 0; sec = 0; 
	int i = 0;
	while(c[i] != ':')
	{
		hou = hou * 10 + c[i] - '0';
		++i;
	}
	++i;
	while (c[i] != ':')
	{
		min = min * 10 + c[i] - '0';
		++i;
	}
	++i;
	while (c[i] != 0)
	{
		sec = sec * 10 + c[i] - '0';
		++i;
	}
}
Time::~Time()
{
}
Time& Time::operator=(const Time& t)
{
	hou = t.hou; min = t.min; sec = t.sec;
	return (*this);
}
Time Time::operator+(const Time& t)
{
	Time res;
	res.sec = sec + t.sec;
	res.min = min + t.min;
	res.hou = hou + t.hou;
	if (res.sec >= 60)
	{
		res.min += 1;
		res.sec -= 60;
	}
	if (res.min >= 60)
	{
		res.hou += 1;
		res.min -= 60;
	}
	if (res.hou >= 24)
		res.hou -= 24;
	return res;
}
Time& Time::operator+=(int _sec)
{
	int a = (hou * 60 + min) * 60 + sec;
	a += _sec;
	hou = (a / 3600) % 24;
	min = a % 3600 / 60;
	sec = a % 60;
	return (*this);
	return (*this);
}
Time Time::operator-(const Time& t)
{
	Time res;
	res.sec = sec - t.sec;
	res.min = min - t.min;
	res.hou = hou - t.hou;
	if (res.sec <= 0)
	{
		res.min -= 1;
		res.sec += 60;
	}
	if (res.min <= 0)
	{
		res.hou -= 1;
		res.min += 60;
	}
	if (res.hou <= 0)
		res.hou += 24;
	return res;
}
Time& Time::operator-=(int _sec)
{
	int a = (hou * 60 + min) * 60 + sec;
	a -= _sec;
	while (a < 0) a += 24 * 60 * 60;
	hou = a / 3600;
	min = a % 3600 / 60;
	sec = a % 60;
	return (*this);
}
bool Time::operator<(const Time& t)
{
	return (hou * 60 + min) * 60 + sec < (t.hou * 60 + t.min) * 60 + t.sec;
}
bool Time::operator>(const Time& t)
{
	return (hou * 60 + min) * 60 + sec > (t.hou * 60 + t.min) * 60 + t.sec;
		
}
bool Time::operator==(const Time& t)
{
	return (hou == t.hou) && (min == t.min) && (sec == t.sec);
}
void Time::readTime()
{
	std::ifstream strIn("Time.txt");
	strIn >> hou >> min >> sec;
	strIn.close();
}
void Time::writeTime()
{
	std::ofstream strOut("Time.txt");
	strOut << hou << " " << min << " " << sec << std::endl;
	strOut.close();
}
std::ostream& operator<< (std::ostream& stream, const Time& t)
{

	if (t.hou < 10)
		stream << '0';
	stream << t.hou << ':';
	if (t.min < 10)
		stream << '0';
	stream << t.min << ':';
	if (t.sec < 10)
		stream << '0';
	stream << t.sec << std::endl;
	return stream;
}
std::istream& operator>> (std::istream& stream, Time& t)
{
	do {
		
		stream >> t.hou;
	} while (t.hou < 0 || t.hou > 24);
	do {
		
		stream >> t.min;
	} while (t.min < 0 || t.min > 60);
	do {
		stream >> t.sec;
	} while (t.sec < 0 || t.sec > 60);
	return stream;
}