#include <iostream>
#include<clocale>
using namespace std;



int trtype(int max, int s2, int s3)
{
	if (max > s2 + s3) return -1; // проверка на существование 
	if (pow(max, 2) > pow(s2, 2) + pow(s3, 2)) // проверка на тупоугольность(квадрат большей стороны больше суммы квадратов других)
		return 0;
	else if (pow(max, 2)< pow(s2, 2) + pow(s3, 2)) // проверка на остроугольность
		return 1;
	else return 2; // иначе прямоугольный
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;
	cout<<"Введите стороны"<<endl;
	cin >> a >> b >> c;
	int max=a;  // находим наибольшую сторону
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	int res;
	if (max == a) 
		res = trtype(a, b, c);
	else if (max == b)
		res = trtype(b, c, a);
	else res = trtype(c,b, a);
	if (res ==-1)
		cout << "Треугольник не существует";
	else if(res == 0)
		cout << "Тупоугольный";
	else if (res == 1)
		cout << "Остроугольный";
	else cout << "Прямоугольный";
	return 0;








}