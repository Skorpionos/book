#include <vector>
#include <fstream>
#include <iostream>

size_t N;
size_t M;

std::vector<int> vector;

std::vector<bool> use;

using std::cin;
using std::cout;

void Print()
{

    for (size_t index = 0; index < N; ++index)
    {
        if (index)
            cout << " ";
        cout << vector[index];
    }
    cout << "\r\n";
}

void Do(size_t position)
{
    if (position == N)
        return Print();

    for (size_t index = 1; index <= N; ++index)
    {
        if (use[index])
            continue;

        vector[position] = index;
        use[index] = true;
        Do(position + 1);
        use[index] = false;
    }
}

int main()
{
//    cin >> N >> M;
    N = 2;
//    M = 3;

    vector = std::vector<int>(N + 1, 0);
    use = std::vector<bool>(N + 1, false);

    Do(0);

//    cout.close();
    return 0;
}

