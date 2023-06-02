//
// Created by Hossein on 6/1/2023.
//

#include "Array.h"

Array::Array(const int array[], int length, int size) : length(length), size(size), array(new int[size])
{
    for (int i = 0; i < length; ++i)
    {
        this->array[i] = array[i];
    }
}

Array::~Array()
{
    delete[] array;
}

void Array::display() const
{
    std::cout << *this;
}

int Array::binarySearch(int value) const
{
    int firstIndex = 0;
    int lastIndex = length - 1;
    while (lastIndex >= firstIndex)
    {
        int midIndex = (firstIndex + lastIndex) / 2;
        if (array[midIndex] == value)
        {
            return midIndex;
        }
        else if (array[midIndex] > value)
        {
            lastIndex = midIndex - 1;
        }
        else if (array[midIndex] < value)
        {
            firstIndex = midIndex + 1;
        }
    }
    return -1;
}

int Array::recursiveBinarySearch(int value, int firstIndex, int lastIndex)
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
        return recursiveBinarySearch(value, midIndex + 1, lastIndex);
    }
    else if (value < array[midIndex])
    {
        return recursiveBinarySearch(value, firstIndex, midIndex - 1);
    }
}

void Array::insertInSortedArray(int value)
{
    if (length == size)
    {
        return;
    }
    int i;
    for (i = length - 1; array[i] > value; --i)
    {
        array[i + 1] = array[i];
    }
    array[i + 1] = value;
    length++;
}

bool Array::isSorted() const
{
    for (int i = 0; i < length - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void Array::leftNegativeRightPositive()
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (array[i] >= 0)
        {
            i++;
        }
        while (array[j] < 0)
        {
            j--;
        }
        if (i < j)
        {
            std::swap(array[i], array[j]);
        }
    }
}

Array Array::mergeSortedArrays(const Array& first, const Array& second)
{
    int resultLength = first.length + second.length;
    Array result({}, 0, resultLength);

    int total = 0;
    int i = 0;
    int j = 0;
    while (total < resultLength)
    {
        if (first[i] < second[j] && i < first.length)
        {
            result.push_back(first[i++]);
        }
        else
        {
            result.push_back(second[j++]);
        }
        total++;
    }
    return result;
}

void Array::push_back(int value)
{
    if (length == size)
    {
        return;
    }
    array[length] = value;
    length++;
}
