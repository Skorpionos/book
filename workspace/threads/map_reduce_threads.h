#include "internal/io.h"
#include "internal/time.h"

#include <thread>
#include <vector>

template <class It, class F1, class F2, class R>
R reduce(It begin, It end, F1 f1, F2 f2, R& result)
{
    auto it = begin;
    result = f1(*it);
    while (++it != end)
        result = f2(result, f1(*it));
}

template <class It, class F1, class F2>
auto map_reduce(It begin, It end, F1 f1, F2 f2, size_t threadsCount)
{
    using Result = decltype(f1(*begin));

    const auto length = std::distance(begin, end);
    const auto interval = static_cast<size_t>(length / threadsCount);

    std::vector<Result> results(threadsCount);

    std::vector<std::thread> threads(threadsCount);

    auto left  = begin;
    auto right = std::next(left, interval + length % threadsCount);

    for (size_t counter = 0; counter < threadsCount - 1; ++counter)
    {
        threads[counter] = std::thread(reduce<It, F1, F2, Result>,
                           left,
                           right,
                           f1,
                           f2,
                           std::ref(results[counter]));

        left = right;
        std::advance(right, interval);
    }

    reduce(left, right, f1, f2, results[(threadsCount - 1)]);

    for (size_t index = 0; index < threadsCount - 1; ++index)
        threads[index].join();

    Result result;
    reduce(results.begin(), results.end(), [](auto item) {return item;}, f2, result);
    return result;
}

int main()
{
    std::vector<int64_t> vector;

    for (int64_t index = 1; index <= 10; ++index)
        vector.push_back(index);

    const auto time0 = ch::steady_clock::now();

    auto sum = map_reduce(vector.begin(),
                          vector.end(),
                          [](auto i){return i;},
                          std::plus<>(),
                          2);

    std::cout << sum << "\n";

    util::SolveDeltaTime(time0);

    util::PrintComplete();
}
