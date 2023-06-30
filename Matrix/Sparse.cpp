#include "Sparse.h"

Sparse::Sparse(int n, int m, int size) : n(n), m(m), size(size), elements(new Element[size])
{
}

Sparse::~Sparse()
{
    delete[] elements;
}

std::ostream& operator<<(std::ostream& out, const Sparse& sparse)
{
    int k = 0;
    for (int i = 0; i < sparse.n; ++i)
    {
        for (int j = 0; j < sparse.m; ++j)
        {
            if (i == sparse.elements[k].i && j == sparse.elements[k].j) // Practice this condition
            {
                out << sparse.elements[k++].value << '\t';
            }
            else
            {
                out << 0 << '\t';
            }
        }
        out << '\n';
    }

    return out;
}

std::istream& operator>>(std::istream& in, const Sparse& sparse)
{
    std::cout << "Please enter all the elements: \n";
    for (int i = 0; i < sparse.size; ++i)
    {
        in >> sparse.elements[i].i >> sparse.elements[i].j >> sparse.elements[i].value;
    }
    return in;
}

Sparse operator+(const Sparse& first, const Sparse& second)
{
    if (first.n != second.n && first.m != second.m)
    {
        std::cerr << "Not in the same dimensions";
    }
    Sparse result(first.n, second.m, first.size + second.size);

    int i = 0, j = 0, k = 0;
    // practice end condition
    while (i < first.size && j < second.size)
    {
        if (first.elements[i].i < second.elements[j].i)
        {
            result.elements[k++] = first.elements[i++];
        }
        else if (first.elements[i].i > second.elements[j].i)
        {
            result.elements[k++] = second.elements[j++];
        }
        else
        {
            if (first.elements[i].j < second.elements[j].j)
            {
                result.elements[k++] = first.elements[i++];
            }
            else if (first.elements[i].j > second.elements[j].j)
            {
                result.elements[k++] = second.elements[j++];
            }
            else
            {
                result.elements[k] = first.elements[i++];
                result.elements[k++].value += second.elements[j++].value;
            }
        }
    }

    // copy the rest of elements if one the sparse matrix ends
    for (; i < first.size; i++)
    {
        result.elements[k++] = first.elements[i];
    }
    for (; j < second.size; j++)
    {
        result.elements[k++] = second.elements[j];
    }

    return result;
}
