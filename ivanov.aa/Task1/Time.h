#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time {
	private:
		int hou;
		int min;
		int sec;

	public:
		//Конструкторы
		Time(); // Конструктор по умолчанию
		Time(const Time& c); // Конструктор копирования
		Time(int sec); // Конструктор преобразования типа 
		Time(const char *str); // Конструктор преобразования типа для 11:11:11
		Time(int h, int m, int s); // Конструктор инициализатор

		//Деструктор
		~Time(); 

		//Методы
		void TimeOut(void); // Вывод в формате 11:11:11
		int GetHou() { return hou; } // Получение кол-ва часов
		int GetMin() { return min; } // Получение кол-ва минут
		int GetSec() { return sec; } // Получение кол-ва секунд
		int TimeInSec() { return hou * 3600 + min * 60 + sec; } // Получение времени в секундах полностью
		void SetHou(int h) { hou = h % 24; } // Задание кол-ва часов |(методы нужны, если требуется отдельно изменить
		void SetMin(int m) { min = m % 60; } // Задание кол-ва минут |кол-во часов/минут/секунд)
		void SetSec(int s) { sec = s % 60; } // Задание кол-ва секунд|
		char* TimeToString(void); // Перевод времени в строку

		//Перегрузки
		Time& operator= (const Time& c); // Перегрузка присваивания
		Time operator+ (const Time& c); // Перегрузка сложения для того же класса
		Time operator+ (int _sec); // Перегрузка сложения с секундами
		Time operator- (const Time& c); // Перегрузка вычитания для того же класса
		Time operator- (int _sec); // Перегрузка вычитания с секундами
		Time operator* (int ti); // Перегрузка умножения времени на какое-то целое число
		Time operator/ (int de); // Перегрузка деления времени на какое-то целое число

		bool operator> (const Time& c); // Перегрузка операции >
		bool operator>= (const Time& c); // Перегрузка операции >=
		bool operator< (const Time& c); // Перегрузка операции <
		bool operator<= (const Time& c); // Перегрузка операции <=
		bool operator== (const Time& c); // Перегрузка операции ==

		friend std::ostream& operator<< (std::ostream& out, Time& c); // Перегрузка <<
		friend std::istream& operator>> (std::istream& in, Time& c); // Перегрузка >>
};

#endif