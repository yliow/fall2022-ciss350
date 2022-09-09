// main.cpp
#include <iostream>
#include "Matrix.h" // mat, Mat, mat4x4

int main()
{
    Matrix m(3, 4); // m.p_ is double *

    std::cout << "m(1,2): " << m(1, 2) << '\n';
    m(1, 2) = 42;
    std::cout << "m(1,2): " << m(1, 2) << '\n';

    std::cout << m << '\n';
    return 0;
}
