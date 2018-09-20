#pragma once

#include <iostream>

struct Person
{
using Rating = int;

public:
    static size_t currentId;

    Person(std::string name_, int rating_)
            : name(std::move(name_))
            , rating(rating_)
    {
        id = ++currentId;
    }

    bool operator<(const Person& x) { return this->rating < x.rating; }

    bool operator==(const Person& person) const { return this->id == person.id; }
    bool operator==(const size_t& id_) const { return this->id == id_; }
    bool operator==(const std::string& name_) const { return this->name == name_; }
    bool operator==(const Rating& rating_) const { return this->rating == rating_; }

    void Print() const
    {
        std::cout << id << "-" << name << ": " << rating << "\n";
    }

    size_t id;
    std::string name;
    Rating rating = 0;
};

size_t Person::currentId = 0;