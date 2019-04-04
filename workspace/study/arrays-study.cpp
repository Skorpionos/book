#include "../internal/utility.h"

namespace study
{

void RotateOneStep(int array[], unsigned size)
{
    for (unsigned index = 0; index < size - 1; ++index)
        util::Swap(array[index], array[index + 1]);
}

void Rotate(int array[], unsigned size, int shift)
{
    for (auto index = shift % size; index--;)
        RotateOneStep(array, size);
}

template <class T>
bool Max(T* iter1, const T* iter2, T** result)
{
    if (iter1 >= iter2)
        return  false;

    *result = iter1;

    for (; iter1 != iter2; ++iter1)
        if (*iter1 > **result)
            *result = iter1;
    return true;
}

} // namespace study