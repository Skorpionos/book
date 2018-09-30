#include "study/matrix.h"
#include "internal/io.h"

int main()
{
    auto matrix = matrix::Create<int>(10, 3);

    matrix::Fill(matrix);

    std::cout << matrix[2][2] << "\n";

    matrix::Print(matrix);
}




