#include <iostream>

class ILogger
{
public:
    virtual void print(const std::string&) = 0;
    virtual void print(int a, const std::string&)
    {
    }

    virtual void flush()
    {
        std::cout << "ILogger::flush" << std::endl;
    }
};

class Printer : public ILogger
{
public:
    void print(const std::string&) override
    {
        std::cout << "Printer::print" << std::endl;
    }
    void print(int a)
    {
        std::cout << "Printer::print(10)" << std::endl;
    }
    void print(int, const std::string&) override final
    {
        std::cout << "Printer::print(string, int)" << std::endl;
    }
};

class SuperPrinter : public Printer
{
public:
    /*void print(int, const std::string&) override
    {
        std::cout << "SuperPrinter::print(string, int)" << std::endl;
    }*/

    void print(int)
    {
        std::cout << "SuperPrinter::print(int)" << std::endl;
    }
};

class Console : public ILogger
{
public:
    void print(const std::string&) override
    {
        std::cout << "Console::print" << std::endl;
    }
};

class FileWriter : public ILogger
{
    void print(const std::string&) override
    {
        std::cout << "FileWriter::print" << std::endl;
    }
};

void log(ILogger* logger, const std::string& message)
{
    logger->print( message );
    logger->flush();
}

struct A
{
    A()
    {
        std::cout << "A()" << std::endl;
    }
    int a;
};

struct B : virtual A
{
    B()
    {
        std::cout << "B()" << std::endl;
    }
    int b;
};

struct C : virtual A
{
    C()
    {
        std::cout << "C()" << std::endl;
    }
    int c;
};

struct D : B, C
{
    D()
    {
        std::cout << "D()" << std::endl;
    }
    int d;
};

int main()
{
    ILogger* logger = new FileWriter;
    log( logger, "Say my name" );
    Printer* printer = new SuperPrinter;
    printer->print(10);
    printer->print(10, "Hello");

    D d;
    std::cout << "sizeof(D) = " << sizeof(D) << std::endl;
}
