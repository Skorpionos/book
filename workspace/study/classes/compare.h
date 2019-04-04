template <class T>
struct Less
{
    bool operator()(T a, T b) const
    {
        return a < b;
    }
};

template <class T>
bool less(T a, T b)
{
    return a < b;
}

template <class T, class Compare>
void Sort(T* begin, T* end, Compare less)
{
    for (auto it = begin; it != end; ++it)
        std::cout << less(4, *it) << " ";
    std::cout << "\n";
}

template <class T, class C>
T minimum(Array<T> array, C comparator)
{
    if (array.size() == 0)
        return {};

    auto minimum = array[0];

    for (size_t index = 1; index < array.size(); ++index)
    {
        if (!comparator(minimum, array[index]))
            minimum = array[index];
    }
    return minimum;
}

//int main()
//{
//    srand(time(NULL));
//
//    Array<int> array(10, 5);
//    for (auto index = 0; index < array.size(); ++index)
//        array[index] = rand() % 200;
//
//    for (auto index = 0; index < array.size(); ++index)
//        std::cout << array[index] << " ";
//    std::cout << "\n";
//
////    const auto result = minimum(array, less<int>);
//    const auto result = minimum(array, Less<int>());
//
//    std::cout << result << "\n";
//
//    return util::PrintComplete();
//}