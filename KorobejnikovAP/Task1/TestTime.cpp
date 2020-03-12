#include <iostream>
#include "Time.h"
#include <fstream>
using namespace  std;
int main() {
	Time t1,t2(t1),t3("12:20:14"),t4(1,5,55);
	cout << t1 << "\n" << t2 << "\n" << t3 << "\n" << t4 << "\n";
	string str = t4.ToString();
	cout << str << endl;
	Time t5 = t3 + t4;
	cout << t5 << endl;
	Time t6 = t3;
	cout << t6 << endl;
    Time t7 = t3 - t4;
	cout << t7 << endl;
	if (t2 == t1 && t3 > t4)
		cout << "yes" << endl;
	Time p(23, 00, 15), k(23, 0, 16);
	cout << p - k;
	ofstream strOut("time.txt");
	strOut << t4;
	strOut.close();
	ifstream strIn("time.txt");
	strIn >> t4;
	strIn.close();
	return 0;
}