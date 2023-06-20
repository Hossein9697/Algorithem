#pragma once

#include "Matrix.h"

class Diagonal : public Matrix
{
public:
    explicit Diagonal(int n);

    void set(int i, int j, int value) override;
    int get(int i, int j) override;
    std::ostream& operator<<(std::ostream& out) override;
};