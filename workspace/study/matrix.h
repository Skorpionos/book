#pragma once

#include "cstddef"

namespace util::matrix
{

template <class T>
T** AllocateMemory(size_t N, size_t M)
{
    T** data = new T* [N];

    data[0] = new T [N * M] {};

    for (size_t row = 1; row < N; ++row)
        data[row] = data[row - 1] + M;

    return data;
}

template <class T>
void FreeMemory(T** data, size_t N = 0, size_t M = 0)
{
    delete [] data[0];
    delete [] data;
}

template <class T>
bool Compare(const T* const* data1, size_t N, size_t M, const T* const* data2)
{
    for (size_t row = 0; row < N; ++row)
        for (size_t column = 0; column < M; ++column)
            if (data1[row][column] != data2[row][column])
                return false;
    return true;
}

template <class T, size_t N, size_t M>
bool Compare(const T* const* data1, size_t rowCount, size_t columnCount, T (&data2) [N][M])
{
    for (size_t row = 0; row < rowCount; ++row)
        for (size_t column = 0; column < columnCount; ++column)
            if (data1[row][column] != data2[row][column])
                return false;
    return true;
}

template <class T>
struct Matrix
{
    Matrix<T>(size_t rowsCount, size_t columnsCount)
        : m_rowsCount    {rowsCount}
        , m_columnsCount {columnsCount}
    {
        m_data = AllocateMemory<T>(rowsCount, columnsCount);
    }

    ~Matrix() { FreeMemory(m_data); }

    const T* const* const const_data() const {return m_data;};
    const size_t rows_count()          const {return m_rowsCount;};
    const size_t columns_count()       const {return m_columnsCount;};

    const T* const operator[](size_t row) const { return m_data[row]; }

    T* operator[](size_t row) { return m_data[row]; }

private:
    size_t m_rowsCount = 0;
    size_t m_columnsCount = 0;
    T** m_data = nullptr;
};

template <class T>
Matrix<T> Create(size_t rowsCount, size_t columnsCount)
{
    return Matrix<T>(rowsCount, columnsCount);
}

template <class T>
bool Compare(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
{
    return matrix1.rows_count()    == matrix2.rows_count()    &&
           matrix1.columns_count() == matrix2.columns_count() &&
           Compare(matrix1.const_data(), matrix1.rows_count(), matrix2.columns_count(), matrix2.const_data());
}

template <class T, size_t N, size_t M>
bool Compare(const Matrix<T>& matrix, T (&data2) [N][M])
{
    return matrix.rows_count()    == N &&
           matrix.columns_count() == M &&
           Compare(matrix.const_data(), N, M, data2);
}

template <class T>
void Fill(Matrix<T>& matrix)
{
    size_t index = 0;
    for (size_t row = 0; row < matrix.rows_count(); ++row)
        for (size_t column = 0; column < matrix.columns_count(); ++column)
            matrix[row][column] = ++index;
}

template <class T>
Matrix<T> Transpose(const Matrix<T>& matrix)
{
    auto transposeMatrix = matrix::Matrix<T>(matrix.columns_count(), matrix.rows_count());

    for (size_t row = 0; row < matrix.columns_count(); ++row)
        for (size_t column = 0; column < matrix.rows_count(); ++column)
            transposeMatrix[row][column] = matrix[column][row];

    return transposeMatrix;
}

} // namespace util::matrix

namespace matrix = util::matrix;
