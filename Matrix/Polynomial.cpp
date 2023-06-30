#include "Polynomial.h"

Polynomial::Polynomial(int n) : n(n), terms(new Term[n])
{
}

Polynomial::~Polynomial()
{
    delete[] terms;
}

float Polynomial::value(float x) const
{
    float sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += terms[i].coefficient * std::pow(x, terms[i].exponent);
    }
    return sum;
}

Polynomial Polynomial::operator+(const Polynomial& other)
{
    Polynomial result(n + other.n);
    int i = 0, j = 0, k = 0;
    while (i < n && j < other.n)
    {
        if (terms[i].exponent < other.terms[j].exponent)
        {
            result.terms[k++] = other.terms[j++];
        }
        else if (terms[i].exponent > other.terms[j].exponent)
        {
            result.terms[k++] = terms[i++];
        }
        else
        {
            result.terms[k] = terms[i++];
            result.terms[k++].coefficient += other.terms[j++].coefficient;
        }
    }

    for (; i < n; ++i)
    {
        result.terms[k++] = terms[i++];
    }
    for (; j < other.n; ++j)
    {
        result.terms[k++] = other.terms[j++];
    }
    result.n = k;

    return result;
}

std::istream& operator>>(std::istream& in, const Polynomial& polynomial)
{
    std::cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < polynomial.n; ++i)
    {
        in >> polynomial.terms[i].coefficient >> polynomial.terms[i].exponent;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial)
{
    for (int i = 0; i < polynomial.n; ++i)
    {
        out << '(' << polynomial.terms[i].coefficient << "X^" << polynomial.terms[i].exponent << ')';
        if (i + 1 != polynomial.n)
        {
            out << '+';
        }
    }
    out << '\n';
    return out;
}
