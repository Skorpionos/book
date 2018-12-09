#pragma once

#include <stddef.h>

template <class T>
struct Link
{
    Link(T* ptr_)
        : ptr(ptr_)
        , count(1)
    {}

    T* ptr = nullptr;
    size_t count = 0;
};

template <class T>
struct SharedPtr
{
    explicit SharedPtr(T* ptr_ = nullptr)
    {
        if (ptr_)
            link = new Link<T>(ptr_);
    }

    SharedPtr(SharedPtr& other)
    {
        if (!other.link)
            return;

        link = other.link;
        ++link->count;
    }

    ~SharedPtr()
    {
        if (!link)
            return;

        --link->count;

        if (link->count != 0)
            return;

        delete link->ptr;
        delete link;
    };

    T* get() const {return link->ptr;};

    T& operator*()  const {return *link->ptr;};
    T* operator->() const {return  link->ptr;};

    void Swap(SharedPtr& other)
    {
        std::swap(link, other.link);
    }

    void reset(T *ptr_ = nullptr)
    {
        SharedPtr(ptr_).Swap(*this);
    }

    SharedPtr& operator=(SharedPtr& rhs)
    {
        SharedPtr(rhs).Swap(*this);
        return *this;
    }

    Link<T>* link = nullptr;
};

//#include "study/tasks/evaluate_expression.cpp"
//#include "study/shared_ptr.cpp"
//#include "internal/io.h"
//
//int main()
//{
//    using SharedExpression = SharedPtr<Expression>;
//
//    SharedExpression expression1(new BinaryOperation(-3, '*', new BinaryOperation(4.5, '+', 5)));
//    PrintExpression(*expression1);
//
//    SharedExpression expression2(expression1);
//    PrintExpression(*expression2);
//
//    expression1 = expression1;
//    PrintExpression(*expression1);
//
//    expression2 = expression1;
//    PrintExpression(*expression2);
//
//    expression2.reset(new BinaryOperation(15, '-', 15));
//    PrintExpression(*expression2);
//
//    expression1.Swap(expression2);
//    PrintExpression(*expression1);
//    PrintExpression(*expression2);
//
//    SharedExpression expression3 = expression2;
//    PrintExpression(*expression2);
//
//    util::PrintComplete();
//}