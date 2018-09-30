#pragma once

#include "../internal/utility.h"
#include "../internal/io.h"

// namespace util
// namespace matrix = util::matrix
// namespace study

namespace util
{

void RotateOneStep(int* array, unsigned size);

void Rotate(int* array, unsigned size, int shift);

template <class T>
bool max(T* iter1, const T* iter2, T** result)
{
    if (iter1 >= iter2)
        return  false;

    *result = iter1;

    for (; iter1 != iter2; ++iter1)
        if (*iter1 > **result)
            *result = iter1;
    return true;
}

} // namespace util

namespace study
{

template <class T>
T** CreateMatrix(size_t N, size_t M)
{
    T** matrix = new T* [N];
    for (size_t row = 0; row < N; ++row)
        matrix[row] = new T[M] {};
    return matrix;
}

template <class T>
void DeleteMatrix(T** matrix, size_t N, size_t M = 0)
{
    for (size_t row = 0; row < N; ++row)
        delete [] matrix[row];
    delete [] matrix;
}

void SwapMinRow(int** m, size_t rowsCount, size_t columnsCount)
{
    size_t minRow = 0;
    auto minElement = m[0][0];

    for (size_t row = 0; row < rowsCount; ++row)
        for (size_t column = 0; column < columnsCount; ++column)
            if (minElement > m[row][column])
            {
                minElement = m[row][column];
                minRow = row;
            }

    util::swap(m[0], m[minRow]);
}

} // namespace study
