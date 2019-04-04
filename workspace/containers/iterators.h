#include <type_traits>
#include <iostream>

template <class I>
void AdvanceImpl(I& it, size_t n, std::random_access_iterator_tag)
{
    std::cout << "random_access_iterator_tag" << "\n";
    it += n;
}

template <class I>
void AdvanceImpl(I& it, size_t n, ...)
{
    std::cout << "..." << "\n";
    while (n--)
        ++it;
}

template <class I>
void Advance(I& it, size_t n)
{
    AdvanceImpl(it, n, typename std::iterator_traits<I>::iterator_category());
}