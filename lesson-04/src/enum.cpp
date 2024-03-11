#include <iostream>

enum Color
{
    NONE,
    WHITE,
    BLUE,
    RED
};

enum Shape
{
    Sh_NONE,
    Sh_RECTANGLED,
    Sh_SQUARED
};

enum class CColor
{
    NONE,
    WHITE,
    BLUE,
    RED
};

enum class CShape
{
    NONE,
    RECTANGLED,
    SQUARED
};

Color get_color()
{
    return RED;
}

CColor get_color_class()
{
    return CColor::RED;
}

int main()
{
    Color c = NONE;
    // ...
    c = get_color();
    // ...
    if (c == RED)
    {
        std::cout << "RED" << std::endl;
    }

    CColor cc = CColor::NONE;
    cc = get_color_class();
    if (cc == CColor::RED)
    {
        std::cout << "CColor::RED" << std::endl;
    }
}
