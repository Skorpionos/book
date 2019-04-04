#include "internal/io.h"

#include "containers/array3.h"

struct OtherValueHolder;

struct ValueHolder
{
    std::string value;

    ValueHolder(const int& rhs)
    {
        value = std::to_string(rhs);
    }

    operator OtherValueHolder() const;

    void Print() const
    {
        std::cout << "[test] " << value << "\n";
    };
};


struct OtherValueHolder
{
    std::string value;

    OtherValueHolder(std::string value)
        : value(std::move(value))
    {}

    OtherValueHolder(const ValueHolder& rhs)
    {
        std::cout << "<1> " << __func__ << "\n";
        value = rhs.value;
    }

    void Print() const
    {
        std::cout << "[test] " << value << "\n";
    };
};

ValueHolder::operator OtherValueHolder() const
{
    std::cout << "<2> " << __func__ << "\n";
    return OtherValueHolder(value);
}

std::ostream& operator<<(std::ostream& cout, const ValueHolder& test)
{
    test.Print();
}

std::ostream& operator<<(std::ostream& cout, const OtherValueHolder& test)
{
    test.Print();
}

int main()
{
    Array<ValueHolder> holder1(2, ValueHolder(0));
    holder1[0] = 10;
    holder1[1] = 20;
    holder1.Print();

    Array<OtherValueHolder> holder2 = holder1;

    holder2.Print();

    return util::PrintComplete();
}
