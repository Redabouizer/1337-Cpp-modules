#include <iostream>
#include <string>
#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a=" << a << ", b=" << b << std::endl;
    std::cout << "min(a,b)=" << ::min(a, b) << std::endl;
    std::cout << "max(a,b)=" << ::max(a, b) << std::endl;

    std::string x = "chaine1";
    std::string y = "chaine2";

    ::swap(x, y);
    std::cout << "x=" << x << ", y=" << y << std::endl;
    std::cout << "min(x,y)=" << ::min(x, y) << std::endl;
    std::cout << "max(x,y)=" << ::max(x, y) << std::endl;

    const float cf1 = 4.2f;
    const float cf2 = 4.2f;
    std::cout << "min(cf1,cf2)=" << ::min(cf1, cf2) << std::endl;
    std::cout << "max(cf1,cf2)=" << ::max(cf1, cf2) << std::endl;

    return 0;
}
