// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


class Matrix
{
public:
    Matrix(int nrows, int ncols);
    ~Matrix();

    int nrows() const;
    int ncols() const;
    
    double operator()(int r, int c) const;
    double & operator()(int r, int c);
    
private:
    double * p_;
    int nrows_;
    int ncols_;
};


std::ostream & operator<<(std::ostream &, const Matrix &);

#endif
