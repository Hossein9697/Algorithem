//
// Created by Hossein on 6/1/2023.
//

#ifndef PRACTICE_ARRAY_H
#define PRACTICE_ARRAY_H

#include <iostream>

class Array
{
public:
    Array(const int array[], int length, int size);
    ~Array();

    void display() const;
    [[nodiscard]] int binarySearch(int value) const;
    [[nodiscard]] int recursiveBinarySearch(int value, int firstIndex, int lastIndex);
    void insertInSortedArray(int value);
    [[nodiscard]] bool isSorted() const;
    void leftNegativeRightPositive();
    void push_back(int value);

    static Array mergeSortedArrays(const Array& first, const Array& second);

    inline int& operator[](int index) const
    {
        return array[index];
    }
    friend std::ostream& operator<<(std::ostream& out, const Array& array);

private:
    int* array;
    int length;
    const int size;
};

inline std::ostream& operator<<(std::ostream& out, const Array& array)
{
    for (int i = 0; i < array.length; ++i)
    {
        out << array.array[i] << " ";
    }
    out << '\n';
    return out;
}

#endif // PRACTICE_ARRAY_H
