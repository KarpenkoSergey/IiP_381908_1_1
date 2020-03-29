#pragma once

enum class ExceptionType { outOfBoundsArray,UnacceptableDeg};
struct Exception
{
	ExceptionType error;
	Exception(ExceptionType _error);
};




class Polinom
{
	int deg; 
	double* cft;
public:
	Polinom();                 // Конструктор по умолчанию
	Polinom(const Polinom& c);// Конструктор копирования
	Polinom(int _deg, double* _cft);// Конструктор инициализации
	Polinom(int _deg);           // конструктор преобразования типа
	~Polinom();                 // Деструктор



   
    double value(Polinom c, double x); // значение в заданной точке
    void derv(Polinom& c);             // производная данного полинома
    Polinom operator + (const Polinom&);   //оператор сложения двух полиномов
    Polinom operator = (const Polinom&);   //оператор присваивания
	double& operator[](int ind); // операция индексации 
    const double& operator[](int ind) const; //операция индексации для константных объектов
	void OutputPolinom();   //функция вывода полинома

	friend std::ostream& operator<< (std::ostream& stream, Polinom& p); //ввод в поток
	friend std::istream& operator>> (std::istream& stream, Polinom& p); // вывод из потока
   




};
