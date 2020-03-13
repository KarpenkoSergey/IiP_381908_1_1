#include <iostream> 
#include <clocale>
#include <fstream>
#include "RatNum.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Rational Client1(2, 5), Client2, Client3, Client4, Client5(5, 10);
	Client1.output("Дробь 1:");
	
	Client2.input();
	Client2.output("Дробь 2:");

	Client3 = Client2;
	Client3.output("Дробь 3:");

	Client3 = Client1*Client2;
	Client3.output("Произведение 1 и 2:");

	Client3 = Client1/Client2;
	Client3.output("Частное 1 и 2:");

	Client3 = Client1+Client2;
	Client3.output("Сумма 1 и 2:");

	Client3 = Client1-Client2;
	Client3.output("Разность 1 и 2:");
	
	if (Client1 > Client2)
		cout << "Дробь1 больше дроби 2"<<endl;
	else if (Client1 < Client2)
		cout << "Дробь2 больше дроби 1"<<endl;
	else 
		cout << "Дроби равны";
	
	if (Client1 == Client2)
		cout << "Равны"<<endl;
	else 
		cout << "Не равны"<<endl;
   
	// запись в файл
	ofstream strOut("RatNum.txt");
	int _n=Client1.get_n();
	int  _m=Client1.get_m();
	strOut << _n << " " << " " << _m<<endl;
	strOut.close();

	//чтение из файла
	ifstream strIn("RatNum.txt");
	int Cl1_n, Cl1_m;
	strIn >> Cl1_n >> Cl1_m;
	cout << Cl1_n << "/" << Cl1_m;
	strIn.close();
	return 0;

	

}
