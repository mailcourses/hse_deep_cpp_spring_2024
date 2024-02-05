module;

//#include <iostream>
//#include <string>

export module mexample;

export int square(int number)
{
    return number * number;
}


int nonexported_square(int number)
{
    return number * number;
}

export
{
    int foo() { return nonexported_square(100); }
    int foo_2() { return 500; }
};

export namespace dzen
{
    const char* search(const char* qs)
    {
        return qs;
    }
}

