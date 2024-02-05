#include <iostream>

#define PI 3.141592
#define VAR 10

#define MAX(x, y) ( x > y ? x : y )
#define MULT(x, y) (x) * (y)

#include "common.hpp"
#include "utils.hpp"

int main()
{
    std::cout << "PI: " << PI << std::endl;

    int a = 0;
    /*
    ++a // 1, a = 1
    a++ // 1, a = 2
    */
    std::cout << "MAX(x,y): " << MAX(a++, 5) << std::endl;

    std::cout << "MULT(x,y): " << MULT(1+3, 3+4) << std::endl;
    std::cout << "RED: " << RED << std::endl;
}
