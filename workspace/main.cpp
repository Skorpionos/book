#include <vector>
#include <fstream>
#include <iostream>

size_t N;
size_t M;

std::vector<size_t> vector(N);

using std::cin;
using std::cout;

void Print()
{
    static size_t counter = 0;

    std::cout << "<" << ++counter << "> ";

    for (size_t index = 0; index < N; ++index)
    {
        if (index)
            cout << " ";
        cout << vector[index];
    }
    cout << "\r\n";
}

void Do(size_t currentIndex)
{
    if (currentIndex == N)
        return Print();

    for (size_t m = 1; m <= M; ++m)
    {
        vector[currentIndex] = m;
        Do(currentIndex + 1);
    }
}

int main()
{
    N = 6;
    M = 5;

    vector.resize(N);

    Do(0);

    return 0;
}

