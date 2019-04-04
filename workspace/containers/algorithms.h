#pragma once

//template <template <class> class Container, class T>
//bool IsContain(const Container<T>& container, const T& item)
template <class Container>
bool IsContain(const Container& container, const typename Container::value_type& item)
{
    for (size_t index = 0; index < container.size(); ++index)
        if (item == container[index])
            return true;
    return false;
}

template <class It>
size_t max_increasing_len(It begin, It end)
{
    if (begin == end)
        return 0;

    ptrdiff_t maxLength = 1;

    auto startSegment = begin;

    auto itPrevious = begin;
    auto it = ++begin;

    while (it != end)
    {
        if (*it <= *itPrevious)
        {
            maxLength = std::max(maxLength, std::distance(startSegment, it));
            startSegment = it;
        }
        itPrevious = it;
        ++it;
    }
    maxLength = std::max(maxLength, std::distance(startSegment, it));

    return static_cast<size_t>(maxLength);
}
//int main()
//{
//    const std::list<std::string> l1 = {"7", "8", "9", "4", "5", "6", "1", "2", "3", "4"};
//    size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4
//    std::cout << len1 << "\n";
//
//    const std::list<std::string> l2 = {"-3", "-2", "-1", "0", "0", "1", "2", "3", "4", "5"};
//    size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5
//    std::cout << len2 << "\n";
//}