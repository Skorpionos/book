#include "../internal/io.h"
#include <vector>
#include <list>

template<class T>
class VectorList
{
private:
    using VectT = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    using value_type = T;

    VectorList() = default;
    VectorList(VectorList const &) = default;
    VectorList(VectorList &&) noexcept = default;

    VectorList& operator=(VectorList const &) = default;
    VectorList& operator=(VectorList &&) noexcept = default;

    template<class It>
    void append(It p, It q)
    {
        if (p != q)
            data_.push_back(VectT(p,q));
    }

    bool empty() const { return size() == 0; }

    size_t size() const
    {
        size_t count = 0;
        for (const auto& item : data_)
            count += item.size();
        return count;
    }

    struct const_iterator : std::iterator<std::bidirectional_iterator_tag, const T>
    {
        explicit const_iterator(const ListT* ownerDataArg = {},
                                typename ListT::const_iterator listItArg = {},
                                typename VectT::const_iterator vectItArg = {})
            : list_(ownerDataArg)
            , listIt_(listItArg)
            , vectorIt_(vectItArg)
        {}

        bool operator==(const const_iterator& rhs) const
        {
            return std::tie(this->list_, this->listIt_, this->vectorIt_) ==
                   std::tie(  rhs.list_,   rhs.listIt_,   rhs.vectorIt_);
        }

        bool operator!=(const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }

        const typename const_iterator::reference operator*() const
        {
            return *vectorIt_;
        }

        const typename const_iterator::pointer operator->() const
        {
            return &*vectorIt_;
//            return &**this;
        }

        const_iterator& operator++()
        {
            ++vectorIt_;

            if (vectorIt_ == listIt_->cend() && listIt_ != --list_->cend())
            {
                ++listIt_;
                vectorIt_ = listIt_->cbegin();
            }
            return *this;
        }

        const_iterator operator++(int)
        {
            const auto temp = *this;
            operator++();
            return temp;
        }

        const_iterator& operator--()
        {
            if (vectorIt_ == listIt_->cbegin() && listIt_ != list_->cbegin())
            {
                --listIt_;
                vectorIt_ = --listIt_->cend();
            }
            else
            {
                --vectorIt_;
            }
            return *this;
        }

        const_iterator operator--(int)
        {
            const auto temp = *this;
            operator--();
            return temp;
        }

    private:
        const ListT* list_;
        typename ListT::const_iterator listIt_;
        typename VectT::const_iterator vectorIt_;
    };

    const_iterator begin() const
    {
        if (empty())
            return const_iterator();

        const auto front = data_.cbegin();
        return const_iterator(&data_, front, front->cbegin());
    }

    const_iterator end() const
    {
        if (empty())
            return const_iterator();

        const auto back = --data_.cend();
        return const_iterator(&data_, back, back->cend());
    }

    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(begin());
    }

    void Print()
    {
        std::cout << "size [" << size() << "]\n";

        for (const auto& vector : data_)
        {
            for (const auto& item : vector)
                std::cout << item << " ";
            std::cout << "\n";
        }
    }

private:
    ListT data_;
};

//struct Person
//{
//    size_t id = 0;
//    std::string name;
//
//};
//
//std::ostream& operator<<(std::ostream&, Person person)
//{
//    std::cout << "id: " << person.id << ", name:" << person.name << "\n";
//}
//
//int main()
//{
//    VectorList<int> vectorList; /*
//    util::ShowType<typename std::iterator_traits<VectorList<int>::const_iterator>::iterator_category>();
//    util::ShowType<typename std::iterator_traits<VectorList<int>::const_iterator>::value_type>();
//    util::ShowType<typename std::iterator_traits<VectorList<int>::const_iterator>::difference_type>();
//    util::ShowType<typename std::iterator_traits<VectorList<int>::const_iterator>::pointer>();
//    util::ShowType<typename std::iterator_traits<VectorList<int>::const_iterator>::reference>();
//*/
//
//    std::vector<int> v1 = {1, 2};
//    std::vector<int> v2 = {31, 32, 33};
//    std::vector<int> v3 = {400};
//
//    vectorList.append(v1.begin(), v1.end());
//    vectorList.append(v2.begin(), v2.end());
//    vectorList.append(v3.begin(), v3.end());
//
//    vectorList.Print();
//    util::PrintBreak('=');
//
//    for (const auto& item : vectorList)
//        std::cout << item << " ";
//    std::cout << "\n";
//    util::PrintBreak('=');
//
//    for (auto it = vectorList.rbegin(); it != vectorList.rend(); ++it)
//    {
//        const auto pIt = &it;
//        std::cout << *it << " ";
//    }
//    std::cout << "\n";
//    util::PrintBreak('=');
//
//    const auto vladimir = new Person {1, "Nikolay"};
//    const auto vera     = new Person {2, "Andrey"};
//
//    const auto alexey   = new Person {3, "Sergey"};
//    const auto liliya   = new Person {4, "Stepan"};
//
//    std::vector family1 = {vladimir, vera};
//    std::vector family2 = {alexey, liliya};
//
//    VectorList<Person*> families;
//
//    families.append(family1.begin(), family1.end());
//    families.append(family2.begin(), family2.end());
//
//    for (const auto& personPtr : families)
//        std::cout << personPtr->name << "\n";
//
//    const auto person1It = families.begin();
//
//    std::cout << (*person1It)->name << "\n";
//
//    return util::PrintComplete();
//}