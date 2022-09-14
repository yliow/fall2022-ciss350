// main.cpp
#include <iostream>
#include "Matrix.h" // mat, Mat, mat4x4

int main()
{
    Matrix m(3, 4); // m.p_ is double *

    std::cout << "m.nrows(): " << m.nrows() << '\n';
    std::cout << "m.ncols(): " << m.ncols() << '\n';

    // m(1,2) --> m.operator()(1, 2)
    std::cout << "m(1, 2): " << m(1, 2) << '\n';
    m(1, 2) = 42;
    std::cout << "m(1, 2): " << m(1, 2) << '\n';
    std::cout << m << '\n';

    Matrix n(3, 4);
    n(1, 2) = 1;
    n(2, 2) = 10;
    
    m += n;
    std::cout << m << '\n';

    Matrix p(n);
    std::cout << p << '\n';
    
    Matrix q(100, 100);
    q = m;
    std::cout << q << '\n';
    
    return 0;

    // here ... m.~Matrix() is called
}
