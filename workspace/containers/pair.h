#pragma once

template <class First, class Second>
struct Pair
{
    Pair(const First& firstArg, const Second& secondArg)
        : first(firstArg)
        , second(secondArg)
    {}

    First first {};
    Second second {};
};

template <class First, class Second>
Pair<First, Second> MakePair(const First& first, const Second& second)
{
    return Pair<First, Second>(first, second);
}
