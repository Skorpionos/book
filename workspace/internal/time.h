#pragma once

#include <chrono>

namespace ch = std::chrono;

namespace util
{

using time_point_ns = ch::time_point<ch::steady_clock, ch::nanoseconds>;

decltype(std::chrono::steady_clock::now()) GetNow();

time_point_ns SolveDeltaTime(time_point_ns time0);

} //namespace util