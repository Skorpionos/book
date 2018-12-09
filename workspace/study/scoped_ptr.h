#pragma once

template <class T>
struct ScopedPtr
{
     explicit ScopedPtr(T *ptr = 0) {ptr_ = ptr;};

     ~ScopedPtr() {delete ptr_;};

     T* get() const {return ptr_;};

     T* release()
     {
         const auto temp = ptr_;
         ptr_ = nullptr;
         return temp;
     }

     void reset(T *ptr = 0)
     {
         delete ptr_;
         ptr_ = ptr;
     }

     T& operator*() const {return *ptr_;};

     T* operator->() const {return ptr_;};

private:
    ScopedPtr(const ScopedPtr&) = delete;

    ScopedPtr& operator=(const ScopedPtr&) = delete;

    T *ptr_;
};

//int main()
//{
//    Expression* expression = new BinaryOperation(-3, '*', new BinaryOperation(4.5, '+', 5));
//
//    ScopedPtr<Expression> ptr(expression);
//
//    ptr->Visit(new PrintVisitor); std::cout << "\n";
//
//    std::cout << ptr->Evaluate() << "\n";
//
//    Expression* expression2 = new BinaryOperation(15, '/', 100);
//
//    ptr.reset(expression2);
//
//    ptr->Visit(new PrintVisitor); std::cout << "\n";
//
//    std::cout << ptr->Evaluate() << "\n";
//
//    util::PrintComplete();
//}◙