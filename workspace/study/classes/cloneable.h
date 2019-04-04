#include "internal/io.h"

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() = default;
};

template <typename T>
struct ValueHolder : ICloneable
{
    explicit ValueHolder(const T& data)
        : data_ {data}
    {}

    ValueHolder* clone() const override
    {
        return new ValueHolder(data_);
    }

    T data_;
};

//int main()
//{
//    ValueHolder<int> holder1(100);
//
//    std::cout << holder1.data_ << "\n";
//
//    const auto holder2 = holder1.clone();
//
//    std::cout << holder2->data_ << "\n";
//
//    return util::PrintComplete();
//}
