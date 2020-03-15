#include <iostream>
#include <clocale>
#include "Time.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите время в формате \"00:00:00\": ";
	std::string time = "00:00:00";
	cin >> time;
	Time t1(time); // конструктор преобразования строки в числа 

	cout << "Введите секунды увеличения времени: ";
	int secondsum = 0; // секунды для вырожения +
	cin >> secondsum;
	Time summa(0, 0, secondsum);
	Time t2;
	t2 = t1 + summa;
	cout << t1.TextTime() << " + " << secondsum << " секунды = " << t2.TextTime() << endl;
	
	cout << "Введите секунды уменьшения времени: ";
	int secondrazn = 0;// секунды для вырожения -
	cin >> secondrazn;
	Time raznost(0, 0, secondrazn);
	Time t3;
	t3 = t1 - raznost;
	cout << t1.TextTime() <<  " - " << secondrazn << " секунды = " << t3.TextTime() << endl;
	
	Time t4(t1);
	cout << t4.TextTime() << endl;
	

	if (t3 <= t2)
		cout << "true\n";
	else
		cout << "false\n";



	// Запись в поток
	ofstream os; // поток для записи
	os.open("time.txt"); // файл для записи
	os << t2 << t3 << endl;
	os.close();
	Time c1, c2; // объекты ля проверки чтения из файла
	// Чтение из потока
	ifstream is; // поток для чтения
	is.open("time.txt"); // файл для чтения
	is >> c1 >> c2;
	cout << "t2: " << c1.TextTime() << endl;
	cout << "t3: " << c2.TextTime();
	is.close();

	return 0;
}