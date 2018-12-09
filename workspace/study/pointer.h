#include <iostream>
#include "internal/io.h"

template <class T>
class SmartPointer
{
public:
    SmartPointer()
        : m_data(new T())
    {}

    SmartPointer(T rhs)
    {
//        m_data = new T();
        m_data = &rhs;
    }
    SmartPointer& operator=(T rhs)
    {
        m_data = &rhs;
    }

    T& operator*() {return *m_data;}

//    T* get()
//    {
//        return m_data;
//    }

private:
    T* m_data;
};

int main()
{
    SmartPointer<int> pointer = 30;
//    pointer = 20;

    std::cout << *pointer << "\n";

    util::ShowType(pointer);

}