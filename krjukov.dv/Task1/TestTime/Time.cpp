#include "Time.h"
#include <iostream>
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
	hou = (c[0] - '0') * 10 + c[1] - '0';
	min = (c[3] - '0') * 10 + c[4] - '0';
	sec = (c[6] - '0') * 10 + c[7] - '0';
}
Time::~Time()
{
}
Time Time::operator=(const Time& t)
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
Time Time::operator+=(int _sec)
{
	sec += _sec;
	min += sec / 60;
	hou += min / 60;
	sec %= 60;
	min %= 60;
	hou %= 24;
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
Time Time::operator-=(int _sec)
{
	sec -= _sec;
	if (sec < 0)
	{
	min += (sec / 60 - 1);
	sec -= (sec / 60 - 1) * 60;
	}
	if (min < 0)
	{
		hou += (min / 60 - 1);
		min -= (min / 60 - 1) * 60;
	}
	if (hou < 0)
	{
		hou -= (hou / 24 - 1) * 24;
	}
	return (*this);
}
bool Time::operator<(const Time& t)
{
	if (hou == t.hou)
		if (min == t.min)
			return sec < t.sec;
		else
			return min < t.min;
	else
		return hou < t.hou;
}
bool Time::operator>(const Time& t)
{
	if (hou != t.hou)
		return hou > t.hou;
	else
		if (min != t.min)
			return min > t.min;
		else
			return sec > t.sec;
		
}
bool Time::operator==(const Time& t)
{
	return (hou == t.hou) && (min == t.min) && (sec == t.sec);
}
void Time::showTime()
{
	if (hou < 10)
		std::cout << '0';
	std::cout << hou << ':';
	if (min < 10)
		std::cout << '0';
	std::cout << min << ':';
	if (sec < 10)
		std::cout << '0';
	std::cout << sec << '\n';

	return;
}
void Time::enterTime()
{
	do {
		std::cout << "Hours(from 0 to 24): ";
		std::cin >> hou;
	} while (hou < 0 || hou > 24);
	do {
		std::cout << "Minutes(from 0 to 60): ";
		std::cin >> min;
	} while (min < 0 || min > 60);
	do{
	std::cout << "Seconds: ";
	std::cin >> sec;
	} while (sec < 0 || sec > 60);
}