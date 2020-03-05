//Code written by Burdukov Mikhail 
//Task 1 Number 5 
#pragma once
#include<iostream>


class Time
{
	int sec, min, hour;

public:
	//констукторы и деконструктор 
	Time();
	Time(const Time &c);
	Time(const char* str);
	Time(int h,int m,int s);
	~Time();

	//ћетоды и перегрузки
	 char* ConvertToStr();
	 void Give(int h, int m, int s);
	 Time& operator=(const Time& c);
	 Time operator+(const Time& c);
	 Time operator-(const Time& c);
	 bool operator==(const Time& c);
	 bool	operator >(const Time& c);
	 bool	operator <(const Time& c);
	 bool operator<=(const Time& c);
	 bool operator>=(const Time& c);
	 bool operator!=(const Time& c);
	 friend std::ostream& operator<< (std::ostream& out, const Time& point);
	 friend std::istream& operator>> (std::istream& in,  Time& c);

};



