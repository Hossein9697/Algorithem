#pragma once

#include "Matrix.h"

class Diagonal
{
public:
    explicit Diagonal(int n);
    ~Diagonal();

    void set(int i, int j, int value);
    [[nodiscard]] int get(int i, int j) const;

    friend std::ostream& operator<<(std::ostream& out, const Diagonal& matrix);

private:
    int* array;
    int n;
};

inline std::ostream& operator<<(std::ostream& out, const Diagonal& matrix)
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

static_assert(MatrixConcept<Diagonal, int>);
