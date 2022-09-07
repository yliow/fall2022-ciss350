#include <iostream>

void f(int x)
{
    x = 1;
    std::cout << "f x=" << x << '\n';
    return;
}

void g(int & x)
{
    x = 1;
    std::cout << "g x=" << x << '\n';
    return;
}

void h(int * p)
{
    std::cout << p << '\n';
    *p = 99;
}

int main()
{
    int x = 0;
    f(x);
    std::cout << "main x=" << x << '\n';

    g(x);
    std::cout << "main x=" << x << '\n';

    h(&x);
    std::cout << "h x=" << x << '\n';

    int * p = new int;
    *p = 42;
    std::cout << (*p) << '\n';
    delete p;

    int * p = new int[10000000];
    std::cout << p[5] << '\n';
    delete [] p;

    // uncomment and run this:
    //while (1)
    //{
    //    int * p = new int[10000000];
    //}
    
    return 0;
}
