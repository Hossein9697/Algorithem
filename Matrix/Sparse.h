#pragma once

#include <iostream>

struct Element
{
    int i;
    int j;
    float value;
};

class Sparse
{
public:
    Sparse(int n, int m, int size);
    ~Sparse();
    friend std::ostream& operator<<(std::ostream& out, const Sparse& sparse);
    friend std::istream& operator>>(std::istream& in, const Sparse& sparse);
    friend Sparse operator+(const Sparse& first, const Sparse& second);

private:
    int n;
    int m;
    int size;
    Element* elements;
};