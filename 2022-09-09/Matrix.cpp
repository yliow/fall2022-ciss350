// Matrix.cpp
#include <iostream>
#include "Matrix.h"


Matrix::Matrix(int nrows, int ncols)
    : p_(new double[nrows * ncols]), nrows_(nrows), ncols_(ncols)
{}


Matrix::~Matrix()
{
    delete [] p_;
}


double Matrix::operator()(int r, int c) const
{
    return p_[r * ncols_ + c];
}


double & Matrix::operator()(int r, int c)
{
    return p_[r * ncols_ + c];
}


std::ostream & operator<<(std::ostream & cout, const Matrix & m)
{
    for (int r = 0; r < m.nrows(); ++r)
    {
        cout << '[';
        for (int c = 0; c < m.ncols(); ++c)
        {
            cout << m(r, c) << ' ';
        }
        cout << "]\n";
    }
    return cout;
}


int Matrix::nrows() const
{
    return nrows_;
}


int Matrix::ncols() const
{
    return ncols_;
}
