//
// Created by Hossein on 6/16/2023.
//

#ifndef PRACTICE_STRINGPERMUTATION_H
#define PRACTICE_STRINGPERMUTATION_H

#include <iostream>
#include <string>

void stringPermutation1(const std::string& string, int k)
{
    static char result[4];
    static int temp[3] = {0};

    if (string.length() == k)
    {
        result[k] = '\0';
        std::cout << result << std::endl;
    }

    else
    {
        for (int i = 0; i < string.length(); ++i)
        {
            if (temp[i] == 0)
            {
                result[k] = string[i];
                temp[i] = 1;
                stringPermutation1(string, k + 1);
                temp[i] = 0;
            }
        }
    }
}

void stringPermutation2(std::string string, int low, int high)
{
    if (low == high)
    {
        std::cout << string << std::endl;
    }
    else
    {
        for (int i = low; i <= high; ++i)
        {
            std::swap(string[low], string[i]);
            stringPermutation2(string, low + 1, high);
            std::swap(string[low], string[i]);
        }
    }
}

#endif // PRACTICE_STRINGPERMUTATION_H
