// TODO add iterators (see list-of-vector-iterator.h)
// rename to array.h

#pragma once

#include <cstddef>
#include "../internal/io.h"

template <typename T>
class Array
{
public:
    using value_type = T;

    explicit Array(size_t size, const T& value = T());

    Array() = default;

    Array(const Array& other);
    Array(Array&& rhs);

    template <class O>
    Array(const Array<O>& other);

    Array& operator=(const Array& other);
    Array& operator=(Array&& rhs);

    template <class O>
    Array& operator=(const Array<O>& other);

    ~Array();

    size_t size() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void Swap(Array& other);

    void Print() const;

private:
    size_t m_size = 0;
    T* m_data = nullptr;
};

template <typename T>
Array<T>::Array(size_t size, const T& value)
    : m_size {size}
    , m_data {reinterpret_cast<T*>(new std::byte[m_size * sizeof(T)])}
//  , m_data {reinterpret_cast<T*>(new char[m_size * sizeof(T)])}
//  , m_data {static_cast<T*>(operator new[] (m_size * sizeof(T)))}
{
    for (size_t index = 0; index < m_size; ++index)
        new (m_data + index) T(value);
}

template <class T>
Array<T>::Array(const Array& other)
    : m_size {other.size()}
    , m_data {reinterpret_cast<T*>(new std::byte[m_size * sizeof(T)])}
{
    for (size_t index = 0; index < m_size; ++index)
        new (m_data + index) T(other[index]);
}

template <class T>
void Array<T>::Swap(Array<T>& other)
{
    if (this == &other)
        return;

    std::swap(m_size, other.m_size);
    std::swap(m_data, other.m_data);
}

template<typename T>
Array<T>::Array(Array<T>&& rhs)
{
    std::cout << "this: " << this  << "\n";
    std::cout << "rhs: " << &rhs  << "\n";
    std::cout << "sizeof(*this): " << sizeof(*this)  << "\n";
    Swap(rhs);
}

template <class T>
template <class O>
Array<T>::Array(const Array<O>& other)
    : m_size {other.size()}
    , m_data {reinterpret_cast<T*>(new std::byte[m_size * sizeof(T)])}
{
    for (size_t index = 0; index < m_size; ++index)
        m_data[index] = static_cast<T>(other[index]);
//      new (m_data + index) T(other[index]);
//      new (m_data + index) T(static_cast<T>(other[index])); // ? why not
}


template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        Array<T>(other).Swap(*this);
//        this->~Array();
//        new (this) Array(other);
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs)
{
    std::cout << "this: " << this  << "\n";
    std::cout << "rhs: " << &rhs  << "\n";
    std::cout << "sizeof(*this): " << sizeof(*this)  << "\n";
    Swap(rhs);
    return *this;
}

template <class T>
template <class O>
Array<T>& Array<T>::operator=(const Array<O>& other)
{
    Array<T>(other).Swap(*this);
    return *this;
}

template <class T>
Array<T>::~Array()
{
    auto index = m_size;
    while (index--)
        m_data[index].~T();
//  operator delete[] (m_data);
//  delete[] reinterpret_cast<std::byte*>(m_data);
}

template <class T>
T& Array<T>::operator[](size_t index)
{
    return m_data[index];
}

template <class T>
const T& Array<T>::operator[](size_t index) const
{
    return m_data[index];
}

template <class T>
size_t Array<T>::size() const
{
    return m_size;
}

template <class T>
void Array<T>::Print() const
{
    std::cout << fmt::format("Array[{}]:\n", m_size);
    for (size_t index = 0; index < m_size; ++index)
    {
        std::cout << m_data[index] << " ";
//        m_data[index].Print();
    }
    std::cout << "\n";
}

template <>
class Array<bool>
{
public:
    Array(size_t size, const bool& value);
    bool operator[](size_t index) const;

    void Print() const;

private:
    const static size_t BitsInByte = 8;
    const static size_t BitsInInt = BitsInByte * sizeof(int);

    size_t m_size = 0;
    int* m_data = nullptr;
};

Array<bool>::Array(size_t size, const bool& value)
    : m_size(size)
    , m_data{new int[m_size / BitsInInt + 1]()}
{
}

bool Array<bool>::operator[](size_t index) const
{
    return static_cast<bool>(m_data[index / BitsInInt] & (1 << (index % BitsInInt)));
}

void Array<bool>::Print() const
{
    const size_t bytesInGroup = 4;
    std::cout << fmt::format("Bool array[{}]:\n", m_size);
    for (size_t index = 0; index < m_size; ++index)
    {
        std::cout << (* this)[index];
        if (index % BitsInByte == BitsInByte - 1)
            std::cout << " ";
        if (index % (bytesInGroup * BitsInByte) == bytesInGroup * BitsInByte - 1)
            std::cout << "\n";

    }
    std::cout << "\n";
}

template <template <class> class Container, class T>
Container<std::string> ToString(Container<T> container)
{
    Container<std::string> result(container.size());
    for (size_t index = 0; index < container.size(); ++index)
        result[index] += std::to_string(container[index]);
    return result;
}

template <class T>
void PrintFlat(const T& item, std::ostream& out)
{
    out << item << " ";
}

template <class T>
void PrintFlat(const Array<T>& array, std::ostream& out)
{
    std::cout << "<";
    for (size_t index = 0; index < array.size(); ++index)
        PrintFlat(array[index], out);
    std::cout << ">; ";
}

//struct Person
//{
//    explicit Person(std::string nameArg, size_t ageArg)
//        : name(std::move(nameArg))
//        , age(ageArg)
//        , id(currentId)
//        {
//            ++currentId;
//            std::cout << fmt::format("Person(name, age), id: {}\n", id);
//        };
//
//    Person() = delete;
//    Person(const Person& other)
//        : id(currentId)
//    {
//        ++currentId;
//        age = other.age;
//        name = other.name;
//        std::cout << fmt::format("Person(Person), id: {}, name: {}\n", id, name);
//    }
//
//    Person& operator=(const Person& other) = delete;
//
//    ~Person()
//    {
//        std::cout << fmt::format("~Person(), id: {}\n", id);
//    }
//
//    void Print() const
//    {
//        std::cout << fmt::format("id:{}, name:{}, age:{}\n", id, name, age);
//    }
//
//    static size_t currentId;
//    size_t id = 0;
//    std::string name;
//    size_t age = 0;
//
//};
//
//size_t Person::currentId = 0;
//
//int main()
//{
//    {
//        const size_t size = 1;
//
//        Person alexey("Skopintsev", 38);
//
//        std::cout << "<1>\n";
//        Array<Person> array(size, alexey);
//
//        std::cout << "<2>\n";
//        const auto array2 = array;
//
//        std::cout << "<3>\n";
//        array = array2;
//
//        array2.Print();
//        array.Print();
//    }
//    util::PrintComplete();
//}

//int main()
//{
//    Array x(9, 3.5);
//    util::ShowType(x);
//    x.Print();
//
//    const auto data = ToString(x);
//    util::ShowType(data);
//    data.Print();
//
//    return util::PrintComplete();
//}