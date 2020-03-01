
#include <iostream>
#include "Time.h"
int main()
{
    Time c1, c2(10, 4, 52), c3(c2), c4("18:57:08"), c5=c3+c4;
    c1.showTime();
    c2.showTime();
    c3.showTime();
    c4.showTime();
    if (c4 > c3) std::cout << "c4>c3"<<'\n';
    c5.showTime();
    c1.enterTime();
    c1 -= 100;
    c1.showTime();
    std::cout << -23 % 60;
    
}
