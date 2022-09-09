// Matrix.cpp
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int nrows, int ncols)
{
    p_ = new double[nrows * ncols];
}
