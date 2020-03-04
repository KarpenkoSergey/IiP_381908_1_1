#include <iostream>
#include "Time.h"
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	Time t1, t2(t1), t3(14, 23, 9), t4("15:11:58");
	cout << t1 << "\n" << t2 << "\n" << t3 << "\n" << t4 << "\n";
	string str = t3.ToString();
	cout << str << endl;
	Time t5 = t3 + t4;
	cout << t5 << endl;
	Time t6 = t5;
	cout << t6 << endl;
	Time t7 = t3 - t4;
	cout << t7 << endl;
	if ((t2 == t1) && (t3 < t4))
		cout << "Верно" << endl;
	Time a(11, 19, 35), b("11,19,50");
	cout << a - b << endl;
	return 0;
}