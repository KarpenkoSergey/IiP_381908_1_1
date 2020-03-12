#include "Money.h"

int main() {
	Money c1(1, 60000), c2, c3, c4(600, 200), c5, c6(10, 10), c7(1, 90), c8, c9;
	c2 = c1;
	c3 = c2 - c4;
	c5 = c6 / 2;

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c5 << endl;
	if (c1 > c4)
	{
		cout << "don't show" << endl;
	}
	if (c1 < c4)
	{
		cout << "show" << endl;
	}
	else {
		cout << "don't show" << endl;
	}
	if (c8 == c9) {

		cout << "show" << endl;
	}

	Money* pc1 = new Money(c1);
	delete pc1;
	ofstream out("test.txt");
	out << c1 << endl;
	out << c2 << endl;
	out.close();
	ifstream in("test.txt");
	in >> c2;
	in >> c1;
	in.close();
	return 0;
}