#include "Matrix/Diagonal.h"
#include <iostream>

int main()
{
    std::cout << "Enter N:\t";
    int n;
    std::cin >> n;
    Diagonal<double> matrix(n);
    std::cout << "Enter Numbers:\n";

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <n; ++j)
        {
            double input;
            std::cin >> input;
            matrix.set(i, j, input);
        }
    }
    std::cout << matrix;

    return 0;
}
