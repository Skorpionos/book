#include <vector>
#include <iostream>
#include <string>
#include "internal/io.h"
#include "internal/time.h"

using VectorInt = std::vector<int>;

VectorInt vector;

size_t count;


template <class T>
void PrintItems(T container, size_t size)
{
    for (size_t index = 0; index < size; ++index)
    {
        if (index > 0)
            std::cout << "+";
        std::cout << container[index];
    }

    std::cout << "\r\n";
}

void Do(size_t N, size_t position = 0, int sum = 0, int min = 1)
{
    if (sum == N)
    {
        ++count;
        return PrintItems(vector, position);
    }

    for (size_t addendium = min; addendium <= N - sum; ++addendium)
    {
        vector[position] = addendium;
        Do(N, position + 1, sum + addendium, addendium);
    }
}

int main()
{
    size_t N = 10;

    vector.resize(N);

    const auto time = util::GetNow();

    Do(N);

    util::SolveDeltaTime(time);
    std::cout << count << "\n";

    return 0;
}