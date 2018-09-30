#include <gtest/gtest.h>

#include "../internal/print.h"
#include "../internal/time.h"

#include <numeric>

TEST(Clock, VectorCreateAndFill)
{
    const auto time0 = ch::steady_clock::now();

    std::vector<int> list(100'000'000);

    const auto time1 = util::SolveDeltaTime(time0);

    std::iota(list.begin(), list.end(), 0);

    const auto time2 = util::SolveDeltaTime(time1);
}
