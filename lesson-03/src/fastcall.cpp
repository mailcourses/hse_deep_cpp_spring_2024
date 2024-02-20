struct Foo
{

    void help(/* Foo* this, */int a, int b, int c, int d)
    {
        //this->boo += a;
    }
    int boo = 0;
};

//[[gnu::fastcall]]
void foo1(int a, int b, int c, int d)
{
}

void foo2(int a, int b, int c, int d)
{
}


void foo3(int a, int b, int c, int d, int e, int f, int g, int h, double i, double j)
{
}

void boo1()
{
    foo1(1,2,3,4);
}

void boo2()
{
    foo2(5,6,7,8);
}

void boo3()
{
    foo3(1,2,3,4,5,6,7,8,9.0,10.0);
}

void boo4()
{
    Foo foo;
    foo1(1,2,3,4);
    foo.help(1,2,3,4);
    //Foo::help(1,2,3,4);
}
