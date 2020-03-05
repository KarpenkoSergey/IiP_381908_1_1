
#include <iostream>
#include "Time.h"
int main()
{
    Time c1, c2(10, 4, 52), c3(c2), c4("10:5:3"), c5=c3+c4, c6=c3-c4;
    c1.showTime();
    c2.showTime();
    c3.showTime();
    c4.showTime();
    c5.showTime();
    c6.showTime();
    if (c4 > c3) std::cout << "c4>c3"<<'\n';
    if (c3 < c4) std::cout << "c3<c4" << '\n';
    if (c2 == c3) std::cout << "c2 = c3" << '\n';
    c1.enterTime();
    c1 += 200;
    c1.showTime();
    c1 -= 500;
    c1.showTime();
    std::cin >> c1;
    std::cout << c1;
    
}
