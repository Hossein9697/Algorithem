#pragma once

#include "Matrix.h"

template <typename T>
class Diagonal
{
public:
    explicit Diagonal(int n) : n(n)
    {
        array = new T[n];
    }
    ~Diagonal()
    {
        delete[] array;
    }

    void set(int i, int j, T value)
    {
        if (i == j)
        {
            array[i] = value;
        }
    }
    [[nodiscard]] T get(int i, int j) const
    {
        return (i == j) ? array[i] : 0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Diagonal& matrix);

private:
    T* array;
    int n;
};

static_assert(MatrixConcept<Diagonal<int>, int>);