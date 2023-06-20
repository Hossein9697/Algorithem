#pragma once

#include <iostream>

class Matrix
{
public:
    Matrix(int n) : n(n)
    {
    }
    virtual ~Matrix()
    {
        delete[] array;
    }

    virtual void set(int i, int j, int value) = 0;
    virtual int get(int i, int j) = 0;
    virtual std::ostream& operator<<(std::ostream& out) = 0;

protected:
    int* array;
    int n;
};
