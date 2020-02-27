#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c;
    bool exit;
    cout << "Введите стороны треугольника:" << endl;
    do
    {
        exit = false;
        cin >> a >> b >> c;
        if (b > a) swap(b, a);
        if (c > a) swap(c, a);
        if (a >= b + c)
        {
            cout << "Такого треугольника не существует. Введите стороны еще раз:" << endl;
            exit = true;
        }
    } while (exit);
    cout << "Этот треугольник: ";
    if (pow(a, 2) > pow(b, 2) + pow(c, 2)) 
        cout << "тупоугольный ";
    else if (pow(a, 2) == pow(b, 2) + pow(c, 2)) 
        cout << "прямоугольный ";
        else cout << "остроугольный ";
    if (a == b && b == c)
            cout << "и равносторонний ";
     else if (b == c || a == b || a == c)
            cout << "и равнобедренный ";
    return 0;
}