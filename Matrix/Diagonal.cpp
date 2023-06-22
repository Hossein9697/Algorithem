#include "Diagonal.h"

Diagonal::Diagonal(int n) : n(n), array(new int[n])
{
}

Diagonal::~Diagonal()
{
    delete[] array;
}

void Diagonal::set(int i, int j, int value)
{
    if (i == j)
    {
        array[i] = value;
    }
}

int Diagonal::get(int i, int j) const
{
    return (i == j) ? array[i] : 0;
}
