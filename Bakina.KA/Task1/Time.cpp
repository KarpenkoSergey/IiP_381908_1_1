#include <iostream>
#include <cstdlib>
#include <locale>
#include "Time.h"
using namespace std;

//конструктор по умолчанию
Time::Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}
//конструктор копирования
Time::Time(const Time& t)
{
	hou = t.hou;
	min = t.min;
	sec = t.sec;

}

//конструктор преобразования типа
Time::Time(string t)
{
	int j = 0;
	int dt[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
	{
		if (t[j + 1] != ':' && t[j + 1] != '\0')
		{
			dt[i] = (t[j] - '0') * 10 + t[j + 1] - '0';
			j += 3;
		}
		else
		{
			dt[i] = t[j] - '0';
			j += 2;
		}
	}
	hou = dt[0];
	min = dt[1];
	sec = dt[2];
	(*this).perepol();
}


//конструктор-инициализатор
Time::Time(int _hou, int _min, int _sec)
{
	hou = _hou;
	min = _min;
	sec = _sec;
	(*this).perepol();
}

//деструктор
Time::~Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}

//метод представления класса в виде строки

string Time::TimeToString()
{
	string res("00:00:00");
	res[0] = hou / 10 + '0';
	res[1] = hou % 10 + '0';
	res[3] = min / 10 + '0';
	res[4] = min % 10 + '0';
	res[6] = sec / 10 + '0';
	res[7] = sec % 10 + '0';
	return res;
}

//перегрузка операции присваивания
Time& Time::operator=(const Time& c)
{
	hou = c.hou;
	min = c.min;
	sec = c.sec;
	return *this;
}

void Time::perepol()
{
	min += sec / 60;
	sec %= 60;
	hou += min / 60;
	min %= 60;
	hou %= 24;
}
//перегрузка операции сложения
Time Time::operator+(const Time& c)
{
	Time res;
	res.sec = sec + c.sec;
	res.min = min + c.min;
	res.hou = hou + c.hou;
	(res).perepol();
	return res;
}


//перегрузка операции вычитания
Time Time::operator-(const Time& c)
{
	Time res;
	if (sec < c.sec)
	{
		min--;
		res.sec = 60 + sec - c.sec;
	}
	else
		res.sec = sec - c.sec;

	if (min < c.min)
	{
		hou--;
		res.min = 60 + min - c.min;
	}
	else
		res.min = min - c.min;

	if (hou < c.hou)
	{
		res.hou = 24 + hou - c.hou;
	}
	else
		res.hou = hou - c.hou;
	return res;
}




//перегрузка операции сравнения >
bool Time::operator>(const Time& c)
{

	int k1, k2;
	k1 = hou * 3600 + min * 60 + sec;
	k2 = c.hou * 3600 + c.min * 60 + c.sec;
	return k1 > k2;
}

//перегрузка операции сравнения <
bool Time::operator<(const Time& c)
{
	int k1, k2;
	k1 = hou * 3600 + min * 60 + sec;
	k2 = c.hou * 3600 + c.min * 60 + c.sec;
	return k1 < k2;

}

//перегрузка операции сравнения ==
bool Time::operator==(const Time& c)
{

	int k1, k2;
	k1 = hou * 3600 + min * 60 + sec;
	k2 = c.hou * 3600 + c.min * 60 + c.sec;
	return k1 == k2;
}

//перегрузка операции сравнения >=
bool Time::operator>=(const Time& c)
{
	int k1, k2;
	k1 = hou * 3600 + min * 60 + sec;
	k2 = c.hou * 3600 + c.min * 60 + c.sec;
	return k1 >= k2;
}

//перегрузка операции сравнения <=
bool Time::operator<=(const Time& c)
{
	int k1, k2;
	k1 = hou * 3600 + min * 60 + sec;
	k2 = c.hou * 3600 + c.min * 60 + c.sec;
	return k1 <= k2;
}

//перегрузка операции сравнения !=
bool Time::operator!=(const Time& c)
{
	int k1, k2;
	k1 = hou * 3600 + min * 60 + sec;
	k2 = c.hou * 3600 + c.min * 60 + c.sec;
	return k1 != k2;
}
//перегрузка операции вывода в поток
ostream& operator<<(ostream& stream, const Time& c)
{
	stream << c.hou << ' ' << c.min << ' ' << c.sec << endl;
	return stream;
}

//перегрузка операции ввода в потok
istream& operator>>(istream& stream, Time& c)
{
	stream >> c.hou >> c.min >> c.sec;
	c.perepol();
	return stream;
}

//output
void Time::ToutPut(const char* name)
{

	cout << name << ": hou = " << hou << " min = " << min << " sec = " << sec << endl;

}

//inPut
void Time::TinPut()
{
	cout << "введите часы (от 0 до 24)" << endl;

	cin >> hou;

	cout << "введите минуты (от 0 до 60)" << endl;

	cin >> min;

	cout << "введите секунды (от 0 до 60)" << endl;

	cin >> sec;
	(*this).perepol();
}

int Time::getHour()
{
	return hou;
}
int Time::getMin()
{
	return min;
}
int Time::getSec()
{
	return sec;
}

void Time::setHour(int _hou)
{
	hou = _hou;
}
void Time::setMin(int _min)
{
	min = _min;
}
void Time::setSec(int _sec)
{
	sec = _sec;
}
void Time::setTime(int _hou, int _min, int _sec)
{
	hou = _hou;
	min = _min;
	sec = _sec;
}