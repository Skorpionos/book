#include <cstddef>
#include <typeindex>
#include <functional>
#include <map>
#include <iostream>

struct Shape
{
    virtual ~Shape() = default;
};

struct Rectangle : Shape
{
};

struct Triangle : Shape
{
};

bool is_intersect_r_r(Shape* a, Shape* b)
{
    std::cout << "is_intersect_r_r" << "\n";
    return false;
};

bool is_intersect_r_t(Shape* a, Shape* b)
{
    std::cout << "is_intersect_r_t" << "\n";
    return false;
};

template <class Base, class Result, bool Commutative>
class Multimethod2
{
    using IntersectFunction = std::function<Result (Base*, Base*)>;

public:
    void addImpl(std::type_index type1, std::type_index type2, IntersectFunction function)
    {
        m_methods[{type1, type2}] = function;
    }

    bool hasImpl(const Base* item1, const Base* item2) const
    {
        return hasFunction(item1, item2) ||
               (Commutative && hasFunction(item2, item1));
    }

    Result call(Base* item1, Base* item2) const
    {
        if (hasFunction(item1, item2))
            return callFunction(item1, item2);
        else
            return callFunction(item2, item1);
    }

private:
    using TypePair = std::pair<std::type_index, std::type_index>;

    TypePair MakeTypePair(const Base* item1, const Base* item2) const
    {
        return {typeid(*item1), typeid(*item2)};
    }
    bool hasFunction(const Base* item1, const Base* item2) const
    {
        return m_methods.find(MakeTypePair(item1, item2)) != m_methods.end();
    }

    Result callFunction(Base* item1, Base* item2) const
    {
        return m_methods.at(MakeTypePair(item1, item2))(item1, item2);
    }

    std::map<TypePair, IntersectFunction> m_methods;
};

//int main()
//{
//    Multimethod2<Shape, bool, true> is_intersect;
//
//    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
//    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle),  is_intersect_r_t);
//
//    Shape* s1 = new Triangle();
//    Shape* s2 = new Rectangle();
//
//    if (is_intersect.hasImpl(s1, s2))
//        bool res = is_intersect.call(s1, s2);
//    else
//        std::cout << "There is not function" << "\n";
//
//    return util::PrintComplete();
//}