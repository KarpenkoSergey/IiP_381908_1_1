#include <iostream>
#include <algorithm>

using namespace std;

bool check (int a, int b, int c){
  if (a+b < c || a+c < b || b+c < a)
    return 0;
  return 1;
}

int main() {
    setlocale(LC_ALL,"Russian");
	int a, b, c;
	cin >> a >> b >> c;
	int tmp = max(a,max(b,c));
    if (a == tmp)
        swap(a,c);
    if (b == tmp)
        swap(b,c);
	if (!check(a,b,c)){
        cout<<"треугольника не существует";
	}
	else {
        if (a*a + b*b == c*c)
          cout<<"треугольник прямоугольный";
        if (a*a + b*b > c*c)
          cout<<"треугольник остроугольный";

        if (a*a + b*b < c*c)
          cout<<"треугольник тупоугольный";
	}
}
