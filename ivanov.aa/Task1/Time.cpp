#include "Time.h"
#include <cstdlib>
#include <iostream>

//___________________Конструктор по умолчанию
Time::Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}

//___________________Конструктор копирования
Time::Time(const Time& c)
{
	hou = c.hou;
	min = c.min;
	sec = c.sec;
}

//___________________Конструктор преобразования типа
Time::Time(int seconds)
{
	seconds = seconds % 86400;
	hou = seconds / 3600;
	min = (seconds - hou * 3600) / 60;
	sec = seconds % 60;
}

//___________________Конструктор преобразования типа для формы 11:11:11
Time::Time(const char *str)
{
	int len = (int)strlen(str);
	int count = 0, ch = 0;
	int i = 0, _ch = 0, __ch = 0;
	for (int i = 0; i < len; i++) // Происходит проверка строки на количество в ней знака : 
		if (str[i] == ':')
			count++;
	// В зависимости от формы, введенной пользователем, происходит обработка
	switch (count)
	{
		case 0: // В случае, когда строка имеет вид: "14", однако можно и больше, например, "1412" потом все равно будет происходить распределение
			for (i = 0; i < len; i++)
				ch = ch * 10 + str[i] - '0';
			break;

		case 1: // В случае, когда строка имеет вид: "14:41"
			i = 0; _ch = 0;
			while (str[i] != ':')
			{
				ch = ch * 10 + str[i] - '0';
				i++;
			}
			ch *= 60;
			i++;
			if (i != len)
			{
				while (str[i] != 0)
				{
					_ch = _ch * 10 + str[i] - '0';
					i++;
				}
			}
			ch += _ch;
			break;

		case 2: // В случае, когда строка имеет вид: "14:41:56" (но может быть любая вариация)
			_ch = 0; __ch = 0; i = 0;
			while (str[i] != ':')
			{
				ch = ch * 10 + str[i] - '0';
				i++;
			}
			ch *= 3600;
			i++;
			while (str[i] != ':')
			{
				_ch = _ch * 10 + str[i] - '0';
				i++;
			}
			_ch *= 60;
			i++;
			if (i != len)
			{
				while (str[i] != 0)
				{
					__ch = __ch * 10 + str[i] - '0';
					i++;
				}
			}
			ch += _ch + __ch;
			break;

		default: // В случае, когда строка имеет более двух знаков ':'
			std::cout << "\nВведенная форма некорректна\n";
			break;
	}

	ch = ch % 86400; // Обрезка и обработка
	hou = ch / 3600;
	min = (ch - hou * 3600) / 60;
	sec = ch % 60;
}

//___________________Конструктор инициализатор
Time::Time(int h, int m, int s)
{
	int ch = (h * 3600 + m * 60 + s) % 86400;
	hou = ch / 3600;
	min = (ch - hou * 3600) / 60;
	sec = ch % 60;
}

//__________________Деструктор
Time::~Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}

//____________________________________Методы

//__________________Вывод времени в формате 00:00:00
void Time::TimeOut(void)
{
	char str[9];
	str[8] = 0; str[2] = ':'; str[5] = ':';
	str[0] = hou / 10 + '0'; str[1] = hou % 10 + '0';
	str[3] = min / 10 + '0'; str[4] = min % 10 + '0';
	str[6] = sec / 10 + '0'; str[7] = sec % 10 + '0';
	std::cout << str <<std::endl;
	return;
}

//__________________Возвращение времени в формате строки
char* Time::TimeToString(void)
{
	char* str = new char[9];
	str[8] = 0; str[2] = ':'; str[5] = ':';
	str[0] = hou / 10 + '0'; str[1] = hou % 10 + '0';
	str[3] = min / 10 + '0'; str[4] = min % 10 + '0';
	str[6] = sec / 10 + '0'; str[7] = sec % 10 + '0';
	return str;
}

//____________________________________Перегрузки

//__________________Перегрузка присваивания
Time& Time::operator=(const Time& c)
{
	hou = c.hou;
	min = c.min;
	sec = c.sec;
	return *this;
}

//__________________Перегрузка сложения для того же класса
Time Time::operator+(const Time& c)
{
	Time rs;
	rs.sec = sec + c.sec;
	rs.min = min + c.min + rs.sec / 60;
	rs.sec = rs.sec % 60;
	rs.hou = hou + c.hou + rs.min / 60;
	rs.min = rs.min % 60;
	rs.hou = rs.hou % 24;
	return rs;
}

//__________________Перегрузка сложения для секунд
Time Time::operator+(int _sec)
{
	Time rs;
	int ch = (hou * 3600 + min * 60 + sec + _sec) % 86400;
	rs.hou = ch / 3600;
	rs.min = (ch - hou * 3600) / 60;
	rs.sec = ch % 60;
	return rs;
}

//__________________Перегрузка вычитания для того же класса
Time Time::operator-(const Time& c)
{
	Time rs;
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	tim1 -= tim2;
	if (tim1 < 0)
		tim1 += (-1 * tim1 / 86400 + 1) * 86400;
	rs.hou = tim1 / 3600;
	rs.min = (tim1- hou * 3600) / 60;
	rs.sec = tim1 % 60;

	return rs;
}

//__________________Перегрузка вычитания для секунд
Time Time::operator-(int _sec)
{
	Time rs;
	int tim = hou * 3600 + min * 60 + sec;
	tim -= _sec;
	if (tim < 0)
		tim += (-1 * tim / 86400 + 1) * 86400;
	rs.hou = tim / 3600;
	rs.min = (tim - hou * 3600) / 60;
	rs.sec = tim % 60;
	return rs;
}

//__________________Перегрузка умножения времени на какое-то целое число
Time Time::operator* (int ti)
{
	Time rs;
	rs.hou = hou * ti;
	rs.min = min * ti;
	rs.sec = sec * ti;

	rs.min = rs.min + rs.sec / 60;
	rs.sec = rs.sec % 60;
	rs.hou = rs.hou + rs.min / 60;
	rs.min = rs.min % 60;
	rs.hou = rs.hou % 24;
	return rs;
}

//__________________Перегрузка деления времени на какое-то целое число
Time Time::operator/ (int de)
{
	Time rs;
	int tim;
	tim = hou * 3600 + min * 60 + sec;
	tim = (int) tim / de;
	rs.hou = tim / 3600;
	rs.min = (tim - rs.hou * 3600) / 60;
	rs.sec = tim % 60;
	return rs;
}

//__________________Перегрузка операции >
bool Time::operator>(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 > tim2)
		return true;
	else
		return false;
}

//__________________Перегрузка операции >=
bool Time::operator>=(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 >= tim2)
		return true;
	else
		return false;
}

//__________________Перегрузка операции <
bool Time::operator<(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 < tim2)
		return true;
	else
		return false;
}

//__________________Перегрузка операции <=
bool Time::operator<=(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 <= tim2)
		return true;
	else
		return false;
}

//__________________Перегрузка операции ==
bool Time::operator==(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 == tim2)
		return true;
	else
		return false;
}

//__________________Перегрузка потокового вывода
std::ostream& operator<<(std::ostream& out, Time& c)
{
	if (c.GetHou() >= 0 && c.GetHou() <= 9)
		out << "Время = " << "0" << c.GetHou() << ":";
	else
		out << "Время = " << c.GetHou() << ":";
	
	if (c.GetMin() >= 0 && c.GetMin() <= 9)
		out << "0" << c.GetMin() << ":";
	else
		out << c.GetMin() << ":";

	if (c.GetSec() >= 0 && c.GetSec() <= 9)
		out << "0" << c.GetSec() << '\n';
	else
		out << c.GetSec() << '\n';
	return out;
}

//__________________Перегрузка потокового ввода
std::istream& operator>>(std::istream& in, Time& c)
{
	int _hou, _min, _sec;
	std::cout << "\nВведите кол-во часов: ";
	in >> _hou;
	while (_hou < 0 || _hou > 23)
	{
		std::cout << "Введите время от 0ч до 23ч: ";
		in >> _hou;
	}

	std::cout << "\nВведите кол-во минут: ";
	in >> _min;
	while (_min < 0 || _min > 59)
	{
		std::cout << "Введите время от 0мин до 59мин: ";
		in >> _min;
	}

	std::cout << "\nВведите кол-во секунд: ";
	in >> _sec;
	while (_sec < 0 || _sec > 59)
	{
		std::cout << "Введите время от 0сек до 59сек: ";
		in >> _sec;
	}

	c.hou = _hou;
	c.min = _min;
	c.sec = _sec;
	return in;
}
