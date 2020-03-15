#include <iostream>
#include <cstdlib>
#include "Time.h"
using namespace std;
Time::Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}
Time::Time(const Time& t)
{
	hou = t.hou; min = t.min; sec = t.sec;
}
Time::Time(string s)
{
	hou = 0;
	min = 0;
	sec = 0;
	int i = 0;
	while (s[i] != ':')
	{
		hou = (hou * 10) + (s[i] - '0');
		i++;
	}
	i++;
	while (s[i] != ':')
	{
		min = (min * 10) + (s[i] - '0');
		i++;
	}
	i++;
	while (s[i] != '\0')
	{
		sec = (sec * 10) + (s[i] - '0');
		i++;
	}
}
Time::Time(int _hou, int _min, int _sec)
{
	hou = _hou;
	min = _min;
	sec = _sec;
}
Time::~Time() 
{
	hou = 0; min = 0; sec = 0;
}
string Time::ToString()
{
	string tres("00:00:00");
	tres[0] = (hou / 10) + '0';
	tres[1] = (hou % 10) + '0';
	tres[3] = (min / 10) + '0';
	tres[4] = (min % 10) + '0';
	tres[6] = (sec / 10) + '0';
	tres[7] = (sec % 10) + '0';
	return tres;
}
Time& Time:: operator=(const Time& t)
{
	hou = t.hou;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time Time ::operator + (const Time& t)
{
	Time res;
	if (sec + t.sec >= 60)
	{
		res.sec = sec + t.sec - 60;
		res.min++;
	}
	else res.sec = sec + t.sec;
	if (res.min+min+ t.min >= 60)
	{
		res.min = res.min+min+t.min- 60;
		res.hou++;
	}
	else res.min = res.min + min + t.min;
	if (res.hou + hou + t.hou >= 24)
		res.hou = res.hou + hou + t.hou - 24;
	else res.hou = res.hou + hou + t.hou;
	return res;
}
Time Time ::operator - (const Time& t)
{
	Time res;
	if (sec < t.sec)
	{
		res.sec = sec + 60 - t.sec;
		res.min--;
	}
	else res.sec = sec - t.sec;
	if (min + res.min < t.min)
	{
		res.min = min + res.min + 60 - t.min;
		res.hou--;
	}
	else res.min = min + res.min - t.min;
	if (hou + res.hou < t.hou) 
		res.hou = res.hou + hou + 24 - t.hou;
	else res.hou = res.hou + hou - t.hou;
	return res;
}
bool Time ::operator==(const Time& t)
{
	return ((hou == t.hou) && (min == t.min) && (sec == t.sec));
}
bool Time ::operator>(const Time& t)
{
	if (hou != t.hou)
		return hou > t.hou;
	else if (min != t.min)
			return min > t.min;
		else if (sec!= t.sec)
				return sec > t.sec;
	return 0;
}
bool Time ::operator<(const Time& t)
{
	if (hou != t.hou)
		return hou < t.hou;
	else if (min != t.min)
			return min < t.min;
		else if (sec != t.sec)
				return sec < t.sec;
	return 0;
}
ostream& operator << (ostream& out, const Time& t)
{
	out << t.hou << ':' << t.min << ':' << t.sec;
	return out;
}
istream& operator >> (istream& in,Time& t)
{
	in >> t.hou >> t.min >> t.sec;
	return in;
}
Time Time:: operator + (int _sec) {
	Time res;
	if (sec + _sec < 60) {
		res.hou = hou;
		res.min = min;
		res.sec = sec + _sec;
	}
	else 
	{
		res.sec = (sec + _sec) % 60;
		res.min = min + (sec + _sec) / 60;
		if (res.min > 60) {
			res.hou = hou + res.min / 60;
			res.min %= 60;
		}
		if (res.hou >= 24)
			res.hou = res.hou - 24;
	}
	return res;
}
Time Time:: operator - (int _sec) {
	Time res;
	int tsec = (sec + min * 60 + hou *3600);
	if (_sec < tsec) 
	{
		tsec -= _sec;
		res.hou = tsec / 3600;
		tsec -= res.hou * 3600;
		res.min = tsec / 60;
		tsec -= res.min * 60;
		res.min = tsec;
	}
	else 
	{
		tsec = (3600 * 24 + tsec) - (_sec % 3600 * 24);
		res.hou = tsec / 3600;
		tsec -= res.hou * 3600;
		res.min = tsec / 60;
		tsec -= res.min * 60;
		res.min = tsec;
	}
	return res;
}