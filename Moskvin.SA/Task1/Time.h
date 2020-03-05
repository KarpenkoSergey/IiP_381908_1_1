#pragma once
#include <iostream>
#include <fstream>

class Time
{
private:
	int hou, min, sec;
public:
	Time(); // по умолчанию
	Time(int _hou, int _min, int _sec); // инициализация
 	Time(const Time &t); // копирования
	Time(std::string time); // преобразование типа
	~Time(); // деконструктор
	std::string TextTime(); // преобразование в строку
	Time operator + (const Time& t);
	Time operator - (const Time& t);
	Time& operator = (const Time& t);
	bool operator < (const Time& t);
	bool operator > (const Time& t);
	bool operator <= (const Time& t);
	bool operator >= (const Time& t);
	bool operator == (const Time& t);
	friend std::ostream& operator << (std::ostream& stream, Time& t); // при const Time& t выдаёт ошибку "неразрешённых внешних элементов:1"
	friend std::istream& operator >> (std::istream& stream, Time& t);
};

std::ostream& operator << (std::ostream& stream, Time& t);
std::istream& operator >> (std::istream& stream, Time& t);