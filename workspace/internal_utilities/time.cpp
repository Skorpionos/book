#include "time.h"
#include "print.hpp"

#include <iostream>

namespace util
{

time_point_ns SolveDeltaTime(const time_point_ns time0)
{
//    util::ShowType(time0);
    const auto currentTime = ch::steady_clock::now();

    const auto delta = currentTime - time0;

    const auto ms = static_cast<double>(ch::duration_cast<ch::nanoseconds>(delta).count()) / 1000000.0;

    std::cout <<  "delta, ms: " << ms << "\n";

    return currentTime;
}

} // namespace util