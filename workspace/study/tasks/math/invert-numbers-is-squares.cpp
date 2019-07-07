#include <iomanip>

int main()
{
    constexpr size_t N = 1000;
    std::vector<bool> numbers(N, false);
    std::vector<size_t> counts(N, 0);
    std::vector<std::vector<size_t>> elements(N+1);

//    std::cout << "iteration #" << 0 << " ";
//    for (size_t index = 1; index <= N; ++index)
//    {
//        std::cout << numbers[index] << " ";
//    }
//    std::cout << "\n";

    for (size_t iteration = 1; iteration <= N; ++iteration)
    {
        for (size_t index = 1; index <= N; ++index)
        {
            if (index % iteration == 0)
            {
                numbers[index] = !numbers[index];
                ++counts[index];

                elements[index].push_back(iteration);
            }

        }
//        std::cout << "iteration #" << std::setw(3) << iteration << ": ";
//        for (size_t index = 1; index <= N; ++index)
//        {
//            std::cout << numbers[index] << " ";
//        }
//        std::cout << "\n";
//        for (size_t index = 1; index <= N; ++index)
//        {
//            std::cout << counts[index] << " ";
//        }
//        std::cout << "\n";

    }

    for (size_t index = 1; index <= N; ++index)
    {
//        if (numbers[index] == true)
        {
            std::cout << index << " " << counts[index] << "; ";
            std::cout << 100.0 * counts[index] / index << "; ";
            for (const auto& item : elements[index])
                std::cout << item << " ";
            std::cout << "\n";
        }

    }
}