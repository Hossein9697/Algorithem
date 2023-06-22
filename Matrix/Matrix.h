#pragma once

#include <concepts>
#include <iostream>

template <typename T>
concept IsNumber = std::integral<T> || std::floating_point<T>;

template <typename T>
concept Numeric = std::is_arithmetic<T>::value;

template <typename T>
concept MatrixHasGet = requires(T tempMatrix, int i, int j) {
    {
        tempMatrix.get(i, j)
    } -> IsNumber;
};

template <typename T, typename P>
concept MatrixHasSet = requires(T tempMatrix, int i, int j, P value) {
    requires IsNumber<P>;
    tempMatrix.set(i, j, value);
};

template <typename T>
concept MatrixIsPrintable = requires(T tempMatrix) {
    std::cout << tempMatrix;
};

template <typename T, typename P>
concept MatrixConcept = MatrixHasGet<T> && MatrixHasSet<T, P> && MatrixIsPrintable<T>;
