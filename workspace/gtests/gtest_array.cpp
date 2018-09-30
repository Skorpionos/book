#include <gtest/gtest.h>

#include "../internal/io.h"
#include "../study/arrays.h"

TEST(Matrix, Transpose)
{
    constexpr size_t N = 2;
    constexpr size_t M = 5;

    int testMatrix[N][M] = {{ 1,  2,  3,  4,  5},
                            { 6,  7,  8,  9, 10}};

    auto matrix = matrix::Create<int>(N, M);
//    const auto matrix = matrix::Matrix<int>(N, M);
//    const matrix::Matrix<int> matrix(N, M);
//    const matrix::Matrix<int> matrix {N, M};
    matrix::Fill(matrix);
    matrix::Print(matrix);

    EXPECT_TRUE(matrix::Compare<int>(matrix, testMatrix));

    const auto transposeMatrix = matrix::Transpose(matrix);

    matrix::Print(transposeMatrix);

    const auto transposeTwoMatrix = matrix::Transpose(transposeMatrix);
    matrix::Print(transposeTwoMatrix);

    EXPECT_TRUE(matrix::Compare<int>(matrix, transposeTwoMatrix));

    const auto TransposeThreeMatrix = matrix::Transpose(transposeTwoMatrix);
    matrix::Print(TransposeThreeMatrix);

    EXPECT_TRUE(matrix::Compare<int>(transposeMatrix, TransposeThreeMatrix));

    util::PrintComplete();
}
