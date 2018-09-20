#include <gtest/gtest.h>

#include "../internal_utilities/print.hpp"
#include "../internal_utilities/time.h"

#include <numeric>

TEST(BasicTest, Test1)
{
    const auto time0 = ch::steady_clock::now();
    std::vector<int> list(1000);
    const auto time1 = util::SolveDeltaTime(time0);

    std::iota(list.begin(), list.end(), 0);
    util::PrintContainer(list);
    const auto time2 = util::SolveDeltaTime(time1);
}

TEST(BasicTest, Test2)
{
    std::vector<int> list(1000);
    std::iota(list.begin(), list.end(), 0);
}
