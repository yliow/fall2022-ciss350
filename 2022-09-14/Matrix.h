// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


class IncompatibleError
{};

class Matrix
{
public:
    Matrix(int nrows, int ncols);
    ~Matrix();

    Matrix(const Matrix &);
    const Matrix & operator=(const Matrix &);
    
    int nrows() const;
    int ncols() const;
    
    double operator()(int r, int c) const;
    double & operator()(int r, int c);

    const Matrix & operator+=(const Matrix &);
    Matrix operator+(const Matrix &);

    const Matrix & operator*=(double);
    const Matrix & operator*(double);
    
private:
    double * p_;
    int nrows_;
    int ncols_;
};

Matrix operator*(double, const Matrix &);

std::ostream & operator<<(std::ostream &, const Matrix &);

#endif
