#include "Diagonal.h"

std::ostream& operator<<(std::ostream& out, const Diagonal<int>& matrix)
{
    for (int i = 0; i < matrix.n; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            out << matrix.get(i, j) << "   ";
        }
        out << '\n';
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Diagonal<double>& matrix)
{
    for (int i = 0; i < matrix.n; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            out << matrix.get(i, j) << "   ";
        }
        out << '\n';
    }
    return out;
}
