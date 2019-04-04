struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() = default;
//	virtual void Print() const = 0;
};

template <typename T>
struct ValueHolder : ICloneable
{
    explicit ValueHolder(T data)
        : data_ {std::move(data)}
    {}

    ValueHolder* clone() const override
    {
        return new ValueHolder(data_);
    }

//    void Print() const override
//    {
//        std::cout << data_ << "\n";
//    }

    T data_;
};

class Any
{
public:
    Any() = default;

    template <class T>
    Any(const T& other)
        : value {new ValueHolder<T>(other)}
    {}

    ~Any()
    {
        delete value;
    }

    Any(const Any& other)
    {
        if (other.value)
            value = other.value->clone();
    }

    void Swap(Any& other)
    {
        std::swap(this->value, other.value);
    }

    Any& operator=(const Any& rhs)
    {
        if (this != &rhs)
            Any(rhs).Swap(*this);

        return *this;

    }

    template <class T>
    T* GetAs()
    {
        const auto holder = dynamic_cast<ValueHolder<T>*>(value);
        if (!holder)
            return nullptr;
        return &holder->data_;
    }

//    void Print() const
//    {
//        value->Print();
//    }

    ICloneable* value = nullptr;
};

//int main()
//{
//    Any item;
//    Any item_copy(item);
//
//    item = 100;
//    auto data1 = item.GetAs<int>();
//    std::cout << *data1 << "\n";
//
//    Any item2(item);
//    auto data_x = item.GetAs<int>();
//    std::cout << *data_x << "\n";
//
//    item = 500.99;
//    auto data2 = item.GetAs<double>();
//    std::cout << *data2 << "\n";
//
//    item = std::string("Hi");
//    auto data3 = item.GetAs<std::string>();
//    std::cout << *data3 << "\n";
//
//    item = std::vector<int> {1, 2, 3, 4, 5};
//    auto data4 = item.GetAs<std::vector<int>>();
//    util::PrintContainer(*data4);
//
//    return util::PrintComplete();
//}

//int main()
//{
//    Array array(10, 0);
//    array[0] = 5;
//    array[1] = 15;
//    array[2] = 35;
//
//    array.Print();
//
//    Any holder;
//    holder = 5;
//
//    const auto value1 = holder.GetAs<int>();
//    std::cout << *value1<< "\n";
//
//    holder = array;
//    const auto value2 = holder.GetAs<Array<int>>();
//
//    util::ShowType(value2);
//    util::ShowType(*value2);
//    value2->Print();
//
//    holder = Array<Array<int>>(3, array);
//
//    const auto value3 = holder.GetAs<Array<Array<int>>>();
//    PrintFlat(*value3, std::cout);
//
//    return util::PrintComplete();
//}
