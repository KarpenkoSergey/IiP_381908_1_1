
#include <iostream>
#include "Time.h"
int main()
{
    Time c1, c2(10, 4, 52), c3(c2), c4("10:5:3"), c5=c3+c4, c6=c3-c4;
    std::cout << c1;
    std::cout << c2;
    std::cout << c3;
    std::cout << c4;
    std::cout << c5;
    std::cout << c6;
    if (c4 > c3) std::cout << "c4>c3"<<'\n';
    if (c3 < c4) std::cout << "c3<c4" << '\n';
    if (c2 == c3) std::cout << "c2 = c3" << '\n';
    std::cin >> c1;
    c1 += 200;
    std::cout << c1;
    c1 -= 500;
    std::cout << c1;

    std::cin >> c1;
    c1.writeTime();
    c2.readTime();
    std::cout << c2;
}
