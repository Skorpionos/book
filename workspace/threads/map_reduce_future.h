#include <future>
#include <numeric>
#include <vector>

template <class It, class F1, class F2>
auto reduce(It begin, It end, F1 f1, F2 f2) -> decltype(f1(*begin))
{
    auto it = begin;
    auto result = f1(*it);
    while (++it != end)
        result = f2(result, f1(*it));
    return result;
}

template <class It, class F1, class F2>
auto map_reduce(It begin, It end, F1 f1, F2 f2, size_t threadsCount) -> decltype(f1(*begin))
{
    using Result = decltype(f1(*begin));

    const auto interval = static_cast<size_t>(std::distance(begin, end) / threadsCount);

    std::vector<std::future<Result>> results;

    for (size_t counter = 0; counter < threadsCount; ++counter)
    {
        const auto segmentBegin = std::next(begin, counter * interval);
        const auto segmentEnd   = (counter != threadsCount - 1)
                                  ? std::next(segmentBegin, interval)
                                  : end;
        results.push_back(std::async(std::launch::async, reduce<It, F1, F2>, segmentBegin, segmentEnd, f1, f2));
    }
    return reduce(results.begin(), results.end(), [](std::future<Result>& item) {return item.get();}, f2);
}

// TODO how to use only one lambda:
//auto solve = [](auto begin, auto end, F1& f1, F2& f2)
//{
//    auto it = begin;
//    auto result = f1(*it);
//    while (++it != end)
//        result = f2(result, f1(*it));
//    return result;
//};

//    return std::accumulate(++results.begin(),
//                           results.end(),
//                           results.begin()->get(),
//                           [&f2](auto& value, auto& thread) { return f2(value, thread.get()); });


//    return map_reduce_seq(future_results.begin(), future_results.end(),
//                              [] (typename FutureVector::reference& arg) { return arg.get(); }, binary_functor);
//    return std::accumulate(++results.begin(),
//                           results.end(),
//                           results.begin()->get(),
//                           [&f2](auto& value, auto& thread) { return f2(value, thread.get()); });
//}

//#include "internal/io.h"
//#include "internal/time.h"
//
//#include "threads/map_reduce.h"
//
//int main()
//{
//    std::vector<int64_t> vector;
//
//    for (int64_t index = 0; index <= 100; ++index)
//        vector.push_back(index);
//
//    const auto time0 = ch::steady_clock::now();
//
//    auto sum = map_reduce(vector.begin(),
//                          vector.end(),
//                          [](auto i){return i;},
//                          std::plus<>(),
//                          4);
//
//    std::cout << sum << "\n";
//
//    util::SolveDeltaTime(time0);
//
////    auto result = Solve(vector.begin(), vector.end(), [](auto item){return item;}, [](auto x, auto y) {return x + y;});
////    std::cout << result << "\n";
//
//    util::PrintComplete();
//}