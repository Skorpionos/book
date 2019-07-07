#include <vector>
#include <fstream>
#include <iostream>

size_t N;
size_t M;

std::vector<size_t> vector(N);

//std::ifstream cin("C:\\Projects\\book\\workspace\\input.txt");
//std::ofstream cout("C:\\Projects\\book\\workspace\\output.txt");

using std::cin;
using std::cout;

void Print()
{
//  std::copy(vector.begin(), vector.end(), std::ostream_iterator<size_t>{std::cout, " "});
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
//    cin >> N >> M;
    N = 3;
    M = 2;

    vector.resize(N);

    Do(0);

//    cout.close();
    return 0;
}

