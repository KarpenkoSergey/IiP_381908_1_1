//Code written by Burdukov Mikhail 
//Task 1 Number 5 
#include<iostream>
#include <locale.h>
#include"Time.h"

using namespace std;

int main(){
	setlocale(LC_CTYPE, "Russian");
	//Различные интилизации 
	Time c1,c2(12,12,12),c3("12:13:01");
	Time c4(c2);
	
	//из объекта в строку
	char* str = c2.ConvertToStr();
	int i = 0;
	while (str[i] != NULL) {
		cout << str[i];
		i++;
	}
	cout << endl;
	
	//Операции присваивания , сложения, вычитания , ввод и вывод в поток 
	c2.Give(12, 0, 0);
	c3.Give(0, 1, 1);

	Time c = c2-c3;
	cout <<"Разность : "<< c << endl;

	c = c3;
	cout <<"Присваивание : "<< c << endl;
	
	c = c3+c2;
	cout <<"Сумма : "<<c << endl;

	//Логические операции 
	c.Give(0, 0, 1);
	c1.Give(10, 0, 0);
	cout << "Логические операции" << endl;
	cout << (bool)(c1 > c2) << endl;
	cout << (bool)(c1 < c2) << endl;
	cout << (bool)(c1 == c2) << endl;
	cout << (bool)(c1 >= c2) << endl;
	cout << (bool)(c1 != c2) << endl;
	cout << (bool)(c1 <= c2) << endl;

	return 0;
}