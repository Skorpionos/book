#include <cstdlib>
#include <iostream>

namespace study
{
char *resize(const char *str, size_t size, size_t size_new)
{
    char* str_new = new char[size_new];

    if (size_new < size)
        size = size_new;
    for (unsigned index = 0; index < size; ++index)
        str_new[index] = str[index];

    delete [] str;
    str = nullptr;

    return str_new;
}

void TestMemory()
{
    const size_t size = 1'000'000'000;

    int* array = static_cast<int*>(malloc(size * sizeof(int)));
    std::cout << array << "\n";
    for (size_t index = 0; index < size; ++index)
        array[index] = index;
    std::cout << "ok" << "\n";

    array = static_cast<int*>(realloc(array, 2 * size * sizeof(int)));
    std::cout << array << "\n";
    for (size_t index = 0; index < 2 * size; ++index)
        array[index] = index;
    std::cout << "ok2" << "\n";

    int x;
    std::cin >> x;
    free(array);
    std::cout << "free1" << "\n";

    array = static_cast<int*>(calloc(2 * size, sizeof(int)));
    std::cout << array << "\n";
    for (size_t index = 0; index < 2 * size; ++index)
        array[index] = index;
    std::cin >> x;
    free(array);
    std::cout << "free2" << "\n";
}

} // namespace study