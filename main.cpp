#include "Matrix/Sparse.h"
#include <iostream>

int main()
{
    int n = 4, m = 4, size = 4;
    std::cout << "Enter N x M: ";

    std::cin >> n >> m;

    std::cout << "Enter total numbers1: ";
    std::cin >> size;
    Sparse sparse1(n, m, size);
    std::cout << "Enter total numbers2: ";
    std::cin >> size;
    Sparse sparse2(n, m, size);
    std::cin >> sparse1 >> sparse2;
    //    std::cout << sparse1;
    //    std::cout << sparse2;
    std::cout << sparse1 + sparse2;

    return 0;
}
