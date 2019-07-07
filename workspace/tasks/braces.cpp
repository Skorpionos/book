#include <vector>
#include <iostream>
#include "internal/io.h"
#include "internal/time.h"

size_t N;

using VectorBool = std::vector<bool>;

enum Brace : bool
{
    isOpen   = false,
    isClosed = true,
};

VectorBool vector;

size_t count = 0;

void Print()
{

    for (size_t index = 0; index < 2 * N ; ++index)
    {
        std::cout << (vector[index] ? ")" : "(");
    }
    std::cout << "\r\n";
}

void Do(size_t position, int balance)
{
    if (position == 2 * N)
    {
        if (balance == 0)
        {
            ++count;
//            Print();
        }
        return;
    }

    if (balance > N)
        return;

    vector[position] = isOpen;
    Do(position + 1, balance + 1);

    if (balance == 0)
        return;

    vector[position] = isClosed;
    Do(position + 1, balance - 1);
}

int main()
{
    N = 16;

    vector = VectorBool(2 * N, false);

    const auto time = util::GetNow();

    int balance = 0;
    Do(0, balance);

    std::cout << count << "\n";

    util::SolveDeltaTime(time);

    return 0;
}

//bool IsCorrectBraces(const VectorBool& vector)
//{
//    if (vector.size() % 2)
//        return false;
//
//    int balance = 0;
//    for (size_t index = 0; index < vector.size(); ++index)
//    {
//        if (vector[index])
//            --balance;
//        else
//            ++balance;
//
//         if (balance < 0)
//            return false;
//    }
//    return balance == 0;
//}
