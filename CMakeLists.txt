cmake_minimum_required(VERSION 3.25)
project(Practice)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practice main.cpp Array.cpp Array.h StringPermutation.h Matrix/Matrix.h Matrix/Diagonal.cpp Matrix/Diagonal.h Matrix/Sparse.cpp Matrix/Sparse.h Matrix/Polynomial.cpp Matrix/Polynomial.h)
