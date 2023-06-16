#include "Array.h"
#include "StringPermutation.h"
#include <iostream>

double taylorSeries1(double x, int n)
{
    static double factorial = 1, power = 1;
    if (n == 0)
    {
        return 1;
    }

    double r = taylorSeries1(x, n - 1);
    power *= x;
    factorial *= n;

    return r + power / factorial;
}

double taylorSeries2(double x, int n)
{
    static double result = 1;
    if (n == 0)
    {
        return result;
    }

    result = 1 + x / n * result;
    return taylorSeries2(x, n - 1);
}

//    int ali1[4][3];                                      // in stack
//    int* ali2[3] = {new int[4], new int[4], new int[4]}; // in stack and heap
//    int** ali3 = new int* [3]
//    { new int[4], new int[4], new int[4] };              // in heap
//
//    ali1[1][1] = 15;
//    ali2[1][1] = 15;
//    ali3[1][1] = 15;

int binarySearch(const int* array, int value, int firstIndex, int lastIndex)
{
    if (firstIndex > lastIndex)
    {
        return -1;
    }

    int midIndex = (lastIndex + firstIndex) / 2;
    if (value == array[midIndex])
    {
        return midIndex;
    }
    else if (value > array[midIndex])
    {
        return binarySearch(array, value, midIndex + 1, lastIndex);
    }
    else if (value < array[midIndex])
    {
        return binarySearch(array, value, firstIndex, midIndex - 1);
    }
}

int main()
{
    std::string input = "ABC";
    stringPermutation2(input,0,2);
    return 0;
}
