//Code written by Burdukov Mikhail 
//Task 1 Number 5 
#include<iostream>
#include<stdio.h>
#include<string.h>
#include"Time.h"

//Вспомогательные функции


//констукторы и деконстуктор
Time::Time() {
	hour = 0;
	sec = 0;
	min = 0;
}

Time::Time(const Time& c) {
	hour = c.hour;
	sec = c.sec;
	min = c.min;
}

Time::Time(const char* str) { //поддерживает только строгий формат hh:mm:ss
	hour = (str[0] - '0') * 10 + (str[1]-'0');
	min = (str[3] - '0') * 10 + (str[4] - '0');
	sec = (str[6] - '0') * 10 + (str[7] - '0');
}

Time::Time(int h, int m, int s) {
	hour = h;
	min = m;
	sec = s;
}

Time::~Time() {
	hour = 0;
	min = 0;
	sec = 0;
}

// Методы и перегрузки
void Time::Give(int h,int m,int s) {
	hour = h;
	min = m;
	sec = s;
}

char* Time::ConvertToStr() {
	char* str=new char[8];
	str[0] = hour / 10 + '0';
	str[1] = hour % 10 + '0';
	str[2] = ':';
	str[3] = min /10+'0';
	str[4] = min % 10 + '0';
	str[5] = ':';
	str[6] = sec / 10 + '0';
	str[7] =sec % 10 + '0';
	str[8] = NULL;
	return str;
}

Time& Time::operator=(const Time& c) {
	hour = c.hour;
	min = c.min;
	sec= c.sec;
	return *(this);
}

Time Time::operator+(const Time& c) {
	Time res;
	res.hour = hour + c.hour;
	res.min = min + c.min;
	res.sec = sec + c.sec;
	if (res.sec >= 60) {
		res.min++;
		res.sec %= 60;
	}
	if (res.min >=60) {
		res.hour++;
		res.min %= 60;
	}
	if (res.hour >= 24) {
		res.hour %= 24;
	}
	return res;
}

Time Time::operator-(const Time& c) {
	Time res;
	res.sec = sec - c.sec;
	res.min = min - c.min;
	res.hour = hour - c.hour;
	if (res.sec < 0) {
		res.min--;
		res.sec += 60;
	}
	if (res.min < 0) {
		res.hour--;
		res.min += 60;
	}
	if (res.hour< 0) {
		res.hour += 24;
	}
	return res;
}

bool Time::operator==(const Time& c) {
	return c.hour == hour && c.min == min && c.sec == sec;
}

bool Time::operator>(const Time& c) {
	if (c.hour == hour) {
		if (c.min == min) return sec > c.sec;
		else return min > c.min;
	}
	else return hour > c.hour;
}

bool Time::operator<(const Time& c) {
	return !(*(this) > c) && !(*(this) == c);
}

bool Time::operator<=(const Time& c) {
	return (*(this) < c) || (*(this) == c);
}

bool Time::operator>=(const Time& c) {
	return (*(this) > c) || (*(this) == c);
}

bool Time::operator!=(const Time& c) {
	return !(*this == c);
}

std::ostream& operator<< (std::ostream& out, const Time& c) {
	out << "hours= " << c.hour << " min= " << c.min << " sec= " << c.sec;
	return out;
}

std::istream& operator>> (std::istream& in, Time& c) {
	int h, m, s;
	std::cout <<"Hours= ";
	in >> h;
	std::cout << "Minutes= ";
	in >> m;
	std::cout << "Sec= ";
	in >> s;
	c = { h,m,s };
	return in;
}









