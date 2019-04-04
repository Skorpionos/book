#pragma once

#include <cstddef>
#include "../internal/io.h"

template <class Array>
class ArrayIterator;

template <typename T>
class Array
{
public:
    using Type = T;
public:
    explicit Array(size_t size = 0, const T& value = T());

    Array(const Array& rhs);
    ~Array();

    void Swap(Array& rhs);
    Array& operator=(const Array& rhs);

    size_t size() const;
    T* data() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    ArrayIterator<Array> begin()
    {
        return ArrayIterator(*this, 0);
    }
    ArrayIterator<Array> end()
    {
        return ArrayIterator(*this, m_size);
    }

    void Print();

private:
    size_t m_size = 0;
    T* m_data = nullptr;

};


template<typename T>
Array<T>::Array(size_t size, const T& value)
    : m_size(size)
    , m_data(new T[m_size])
{
    auto index = size;
    while (index--)
        m_data[index] = value;
}

template<typename T>
Array<T>::Array(const Array& rhs)
{
    m_size = rhs.size();
    m_data = new T[m_size];

    auto index = m_size;
    while (index--)
        m_data[index] = rhs.data()[index];
}

template<typename T>
size_t Array<T>::size() const
{
    return m_size;
}

template<typename T>
T* Array<T>::data() const
{
    return m_data;
}

template<typename T>
Array<T>::~Array()
{
    delete [] m_data;
}

template<typename T>
void Array<T>::Swap(Array& rhs)
{
    if (this == &rhs)
        return;

    std::swap(m_size, rhs.m_size);
    std::swap(m_data, rhs.m_data);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if (this != &rhs)
        Array<T>(rhs).Swap(*this);

    return *this;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    return data()[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
    return data()[index];
}

template <class T>
void Array<T>::Print()
{
    for (size_t index = 0; index < m_size; ++index)
        std::cout << m_data[index] << " ";

    std::cout << "\n";
}

template <class Array>
class ArrayIterator
{
public:
    explicit ArrayIterator(Array& array, size_t index = 0)
    : m_array(&array),
      m_index(index)
  {}

//typename Array::Type* GoToBegin()
void GotoBegin()
{
    m_index = 0;
}

void GotoEnd()
{
    m_index = m_array->size();
}

typename Array::Type operator*()
{
    if (m_index >= m_array->size())
        return {};

    return m_array->data()[m_index];
}

typename Array::Type* operator++()
{
    m_index = std::min(++m_index, m_array->size());
}

//private:
    Array* m_array = nullptr;
    size_t m_index = 0;
};

template <class Array>
bool operator==(ArrayIterator<Array> lhs, ArrayIterator<Array> rhs)
{
    return std::tie(lhs.m_array, lhs.m_index) == std::tie(rhs.m_array, rhs.m_index);
}

template <class Array>
bool operator!=(ArrayIterator<Array> lhs, ArrayIterator<Array> rhs)
{
    return !(lhs == rhs);
}
