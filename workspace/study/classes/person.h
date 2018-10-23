#pragma once

#include <iostream>
#include <fmt/format.h>

struct Person
{
using Rating = int;

public:
    Person(std::string name)
            : m_name(std::move(name))
            , m_id(++m_idCounter)
    {
//        fmt::print("Person <{}> {} is created\n", m_id, m_name);
    }

    virtual ~Person()
    {
//        fmt::print("Person <{}> {} is deleted\n", m_id, m_name);
    }

    size_t getId() const {return m_id;};
    const std::string& getName() const {return m_name;}

    bool operator==(const Person& person) const { return this->m_idCounter == person.m_idCounter; }

    virtual void Print() const
    {
        fmt::print("<{}> {}\n", getId(), getName());
    }

private:
    static size_t m_idCounter;
    size_t m_id;
    std::string m_name;
};

size_t Person::m_idCounter = 0;

void Print(const Person& person)
{
    person.Print();
}

enum class Sex
{
    Male,
    Female
};

class Man : public Person
{
public:
    explicit Man(std::string name)
            : Person(std::move(name))
    {
//        fmt::print("Man <{}> {} is created\n", getId(), getName());
    }
    ~Man()
    {
//        fmt::print("Man <{}> {} is deleted\n", getId(), getName());
    }
    virtual void Print() const override

    {
        fmt::print("<{}> {}, man\n", getId(), getName());
    }

private:
    const Sex m_sex = Sex::Male;
};

void Print(const Man& man)
{
    man.Print();
}




// TODO formatter for fmt::print
//template<>
//struct fmt::formatter<Person>
//{
//    template<typename ParseContext>
//    constexpr auto parse(ParseContext& ctx) {return ctx.begin();}
//
//    template<typename FormatContext>
//    auto format(const Person& person, FormatContext& ctx)
//    {
//        return format_to(ctx.begin(), "{}-{}", person.id(), person.name());
//    }
//};
