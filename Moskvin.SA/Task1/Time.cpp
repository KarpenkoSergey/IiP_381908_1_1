#include <iostream>
#include <fstream>
#include "Time.h"

Time::Time() //  ����������� �� ���������
{
	hou = 0;
	min = 0;
	sec = 0;
}
Time::Time(int _hou, int _min, int _sec) // ���������� ������������
{
	hou = _hou;
	min = _min;
	sec = _sec;
}
Time::Time(std::string time) // ����������� �������������� �� ���� string
{
	int i = 0; // ������� ��������
	int n = 0; // ������� ����� � ������
	int tmp[3] = {0,0,0}; // ������ ����� � ������
	while (i <= 8) // ���������� ������ �� ����� � ������ ����� � ������ 
	{
		char a = time[i]; // ���� ���� ������ �� ������
		if (time[i] != ':' && time[i] != '\0')
		{
			tmp[n] += (a - '0');
			if (tmp[n] < 9) tmp[n] *= 10; // �������� �� 10 �.�. ����� �� ������� ����������
		}
		else
		{
			n++;
		}
		i++;
	}
	hou = tmp[0];
	min = tmp[1];
	sec = tmp[2];
} 
Time::~Time() // �������������
{
	hou = 0; min = 0; sec = 0;
}

std::string Time::TextTime() // ����� ������������� � ���� ������
{
	std::string str = "";
	str += hou / 10 + '0';
	str += hou % 10 + '0';
	str += ':';
	str += min / 10 + '0';
	str += min % 10 + '0';
	str += ':';
	str += sec / 10 + '0';
	str += sec % 10 + '0';
	return str;
}

Time Time::operator +(const Time& t)
{
	Time tm;
	tm.hou = hou;
	tm.min = min;
	tm.sec = sec + t.sec;
	while (tm.sec >= 60)
	{
		tm.sec -= 60;
		tm.min++;
	}
	while (tm.min >= 60)
	{
		tm.min -= 60;
		tm.hou++;
	}
	while (tm.hou >= 24)
	{
		tm.hou -= 24;
	}
	return tm;
}

Time Time::operator -(const Time& t)
{
	Time tm;
	tm.hou = hou;
	tm.min = min;
	tm.sec = sec - t.sec;
	while (tm.sec < 0)
	{
		tm.sec += 60;
		tm.min--;
	}
	while (tm.min < 0)
	{
		tm.min += 60;
		tm.hou--;
	}
	while (tm.hou < 0)
	{
		tm.hou = 0;
	}
	return tm;
}

Time& Time::operator =(const Time& t)
{
	hou = t.hou;
	min = t.min;
	sec = t.sec;
	return *this;
}

bool Time::operator < (const Time& t)
{
	if (hou > t.hou)
		return false;
	if (hou == t.hou && min > t.min)
		return false;
	if (hou == t.hou && min == t.min && sec >= t.sec)
		return false;

	return true;
}

bool Time::operator > (const Time& t)
{
	if (hou < t.hou)
		return false;
	if (hou == t.hou && min < t.min)
		return false;
	if (hou == t.hou && min == t.min && sec < t.sec)
		return false;

	return true;
}

bool Time::operator <= (const Time& t)
{
	return sec <= t.sec && min <= t.min && hou <= t.hou;
}

bool Time::operator >= (const Time& t)
{
	return sec >= t.sec && min >= t.min && hou >= t.hou;
}

bool Time::operator == (const Time& t)
{
	return sec == t.sec && min == t.min && hou == t.hou;
}

std::ostream& operator << (std::ostream& stream, Time& t)
{
	stream << t.hou << " " << t.min << " " << t.sec << std::endl;
	return stream;
}

std::istream& operator >> (std::istream& stream, Time& t)
{
	stream >> t.hou >> t.min >> t.sec;

	return stream;
}