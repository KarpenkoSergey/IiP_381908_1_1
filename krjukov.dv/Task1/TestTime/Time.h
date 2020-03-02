#pragma once
class Time
{
private:
	int hou, min, sec;
public:
	Time();
	Time(const Time& t);
	Time(int _hou, int _min, int _sec);
	Time(const char* c);
	~Time();
	Time& operator=(const Time& t);
	Time operator+(const Time& t);
	Time& operator+=(int _sec);
	Time operator-(const Time& t);
	Time& operator-=(int _sec);
	bool operator<(const Time& t);
	bool operator>(const Time& t);
	bool operator==(const Time& t);
	void showTime();
	void enterTime();
	

};

