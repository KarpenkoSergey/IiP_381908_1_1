#include "Time.h"
#include <cstdlib>
#include <iostream>
Time::Time() {
	hou = 0;
	min = 0;
	sec = 0;
}
Time::Time(const Time& t) {
	hou = t.hou; min = t.min; sec = t.sec;
}
Time::Time(string s) {
	hou = (s[0] - '0') * 10 + (s[1] - '0');
	min = (s[3] - '0') * 10 + (s[4] - '0');
	sec = (s[6] - '0') * 10 + (s[7] - '0');
}
Time::Time(int _hou, int _min,int _sec) {
	hou = _hou; min = _min, sec = _sec;
}
Time::~Time() {
	hou = 0; min = 0; sec = 0;
}
string Time:: ToString() {
	string s = "";
	char* str = new char[3];
	_itoa_s (hou, str,3,10);
	hou > 9 ? s = s + str + ":" : s = s + "0" + str + ":";
	_itoa_s(min, str,3, 10);
	min > 9 ? s = s + str + ":" : s = s + "0" + str + ":";
	_itoa_s(sec, str,3, 10);
	sec > 9 ? s += str : s = s + "0" + str;
	return s;
}
Time Time:: operator+ (const Time& t) {
	Time res;
	if (sec + t.sec >= 60) {
		res.sec = sec + t.sec - 60;
		res.min++;
	}
	else
		res.sec = sec + t.sec ;
	if (res.min + min + t.min >= 60) {
		res.min = res.min + min + t.min - 60;
		res.hou++;
	}
	else
		res.min = res.min + min + t.min;
	if (res.hou + hou + t.hou >= 24) {
		res.hou = res.hou + hou + t.hou - 24;
	}
	else
		res.hou = res.hou + hou + t.hou;
	return res;
}
Time& Time:: operator=(const Time& t) {
	sec = t.sec;
	min = t.min;
	hou = t.hou;
	return *this;
}
Time Time:: operator-(const Time& t) {
	Time res;
	if (sec < t.sec) {
		res.sec = sec + 60 - t.sec;
		res.min--;
	}
	else
		res.sec = sec - t.sec;
	if (min + res.min < t.min) {
		res.min = res.min + min + 60 - t.min;
		res.hou--;
	}
	else
		res.min = res.min + min - t.min;
	if (hou + res.hou < t.hou) {
		res.hou = res.hou + hou + 24 - t.hou;
	}
	else res.hou = res.hou + hou - t.hou;
	return res;	
}
bool Time:: operator > (const Time& t) {
	if (hou != t.hou)
		return hou > t.hou;
	else if (min != t.min)
		     return min > t.min;
	     else if (sec != t.sec)
		          return sec > t.sec;
	return 0;
}
bool Time:: operator < (const Time& t) {
	if (hou != t.hou)
		return hou < t.hou;
	else if (min != t.min)
		return min < t.min;
	else if (sec != t.sec)
		return sec < t.sec;
	return 0;
}
bool Time::operator ==(const Time& t) {
	return hou == t.hou && min == t.min && sec == t.sec;
}
ostream& operator << (ostream& out , const Time& t) {
	if (t.hou > 9)
		out << t.hou << ":";
	else out << "0" << t.hou << ":";
	if (t.min > 9)
		out << t.min << ":";
	else out << "0" << t.min << ":";
	if (t.sec > 9)
		out << t.sec ;
	else out << "0" << t.sec ;
	return out;
}
istream& operator >> (istream& in, Time& t) {
	in >> t.hou >> t.min >> t.sec;
	return in;
}