#include <vector>
#include <fstream>
#include <iostream>

size_t N;
size_t M;

using VectorTowns = std::vector<size_t>;
using VectorBool = std::vector<bool>;

VectorTowns path;
VectorBool use;

using Length = uint64_t;
using MatrixLength = std::vector<std::vector<Length>>;

MatrixLength Matrix;

Length minLength = std::numeric_limits<Length>::max();
VectorTowns minPath;

size_t count = 0;

MatrixLength GetMatrixLength()
{
    return
    {
        {0, 1, 3, 4},
        {1, 0, 2, 5},
        {3, 2, 0, 6},
        {4, 5, 6, 0}
    };
}

void Print(VectorTowns vector)
{
    for (size_t index = 0; index < N; ++index)
    {
        if (index)
            std::cout << " ";
        std::cout << vector[index];
    }
    std::cout << " -> ";
}

Length SolveLength(MatrixLength matrix, VectorTowns permutation)
{
    Length length = 0;

    size_t sourceIndex = 0;
    for (size_t index = 0; index < permutation.size(); ++index)
    {
        length += matrix[sourceIndex][permutation[index]];
        sourceIndex = permutation[index];
    }

    length += matrix[sourceIndex][0];
    std::cout << "length: " << length << "\n";
}

void Use()
{
    Print(path);
    SolveLength(Matrix, path);
}

void Do(size_t position, Length currentLength = 0)
{
    if (currentLength > minLength)
        return;

    const auto previousIndex = path[position - 1];

    if (position == N)
    {
        currentLength += Matrix[previousIndex][0];
        if (currentLength < minLength)
        {
            minPath = path;
            minLength = currentLength;
        }
        ++count;
        return;
    }

    for (size_t index = 1; index < N; ++index)
    {
        if (use[index])
            continue;

        path[position] = index;
        use[index] = true;

        Do(position + 1, currentLength + Matrix[previousIndex][index]);
        use[index] = false;
    }
}

int main()
{
    Matrix = GetMatrixLength();

    N = Matrix.size();

    path.resize(N, 0);

    use.resize(N, false);

    Do(1);

    std::cout << "min path: ";
    Print(minPath);
    std::cout << "\n";

    std::cout << "min length: " << minLength << "\n";

    std::cout << "count: " << count << "\n";

    return 0;
}

