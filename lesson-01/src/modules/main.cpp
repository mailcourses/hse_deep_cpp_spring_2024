import mexample;

//import iostream;
#include <iostream>


int main()
{
    std::cout << square(4) << std::endl;
    //std::cout << nonexported_square(4) << std::endl;
    std::cout << foo() << std::endl;
    std::cout << foo_2() << std::endl;
    std::cout << dzen::search("q=hello&n=100") << std::endl;
    return 0;
}
