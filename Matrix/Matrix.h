#pragma once

#include <concepts>
#include <iostream>

template <typename T>
concept MatrixHasGet = requires(T tempMatrix, int i, int j) {
    {
        tempMatrix.get(i, j)
    } -> std::same_as<int>;
};

template <typename T, typename P>
concept MatrixHasSet = requires(T tempMatrix, int i, int j, P value) {
    requires std::integral<P> || std::floating_point<P>;
    tempMatrix.set(i, j, value);
};

template <typename T>
concept MatrixIsPrintable = requires(T tempMatrix) {
    std::cout << tempMatrix;
};

template <typename T, typename P>
concept MatrixConcept = MatrixHasGet<T> && MatrixHasSet<T, P> && MatrixIsPrintable<T>;
