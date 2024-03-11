#include <iostream>

int foo(int a, int b)
{
    std::cout << "foo(int, int)" << std::endl;
    return 0;
}

/*void foo(int a, int b)
{
}
*/
int foo(int& a, int& b)
{
    std::cout << "foo(int&, int&)" << std::endl;
    return 0;
}

using TreeNode = int;

int foo(TreeNode* a, TreeNode* b)
{
    int res = 0;
    if (a != nullptr)
    {
        res += *a;
    }

    if (b)
    {
        res += *b;
    }
    return res;
}

int main()
{
    foo(1, 2);
    int a = 10;
    int b = 20;
    std::cout << foo(&a, &b) << std::endl;
    std::cout << foo(&a, nullptr) << std::endl;
    return 0;
}
