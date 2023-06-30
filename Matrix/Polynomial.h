#pragma once

#include <iostream>

struct Term
{
    float coefficient;
    float exponent;
};

class Polynomial
{
public:
    explicit Polynomial(int n);
    ~Polynomial();
    [[nodiscard]] float value(float x) const;
    Polynomial operator+(const Polynomial& other);

    friend std::istream& operator>>(std::istream& in, const Polynomial& polynomial);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial);

private:
    int n;
    Term* terms;
};
