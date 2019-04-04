#pragma once

#include "../internal/io.h"
#include <fmt/format.h>
#include <set>
#include <unordered_set>

struct Person
{
    Person(std::string nameArg)
        : id(++idCounter)
        , name(nameArg)
    {}

    size_t id = 0;
    std::string name;

    struct Hash
    {
        size_t operator()(const Person& person) const
        {
            std::hash<std::string> h;
            return h(person.name) ^ person.id;
        }
    };

private:
    static size_t idCounter;
};

std::ostream& operator<<(std::ostream& cout, const Person& person)
{
    cout << fmt::format("id: {}, name: {}", person.id, person.name);
}

size_t Person::idCounter = 0;

bool operator==(const Person& lhs, const Person& rhs)
{
    return lhs.id == rhs.id && lhs.name == rhs.name;
}

bool operator<(const Person& lhs, const Person& rhs)
{
    return lhs.id < rhs.id;
}

//namespace std
//{
//template <> struct hash<Person>
//{
//    size_t operator()(const Person& person) const
//    {
//        hash<string> h;
//        return h(person.name) ^ person.id;
//    }
//
//};
//}

//int main()
//{
//    Person alexey("Alexey Skopintsev");
//    Person sergey("Sergey Smirnov");
//    Person nikolay("Nikolay Derevyakin");
//
////    std::unordered_set<Person> people; // for hash<Person> in std
//    std::unordered_set<Person, Person::Hash> people;
//    people.emplace(alexey);
//    people.emplace(sergey);
//    people.emplace(nikolay);
//
//    util::PrintContainer(people);
//
//    return util::PrintComplete();
//}
