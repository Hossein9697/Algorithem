#include "Diagonal.h"

Diagonal::Diagonal(int n) : Matrix(n)
{
    array = new int[n];
}

void Diagonal::set(int i, int j, int value)
{
    if (i == j)
    {
        array[i] = value;
    }
}

int Diagonal::get(int i, int j)
{
    return (i == j) ? array[i] : 0;
}

std::ostream& Diagonal::operator<<(std::ostream& out)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            out << get(i, j) << "   ";
        }
        out << '\n';
    }
    return out;
}
