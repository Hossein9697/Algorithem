#include "Matrix/Polynomial.h"
#include <iostream>

int main()
{
    Polynomial polynomial1(4);
    Polynomial polynomial2(2);
    std::cin >> polynomial1 >> polynomial2;
    std::cout << polynomial1 << polynomial1.value(2) << '\n';
    std::cout << polynomial2 << polynomial2.value(2) << '\n';

    auto polynomial3 = polynomial1 + polynomial2;
    std::cout << polynomial3 << polynomial3.value(2) << '\n';

    return 0;
}
