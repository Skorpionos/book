#pragma once

#include "../containers/list.h"

namespace characters
{

class IActions;

using CharactersList = user::list<IActions*>;

class IActions
{
public:
    virtual void Act() = 0;
};

class Worker : public IActions
{
public:
    void Act() { std::cout << "I work!" << "\n";}
};

class Pirate : public IActions
{
public:
    void Act() { std::cout << "I rob!" << "\n";}
};

class Doctor : public IActions
{
public:
    void Act() { std::cout << "I treat!" << "\n";}
};

void Do(CharactersList characters);

} // namespace characters
