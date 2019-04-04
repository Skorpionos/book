#include "internal/io.h"

struct Unit
{
    Unit(uint32_t id, uint32_t hp)
        : m_id(id)
        , m_hp(hp)
    {}

    uint32_t id() const {return m_id;}

    uint32_t method() const {return m_hp;}

    uint32_t field = 1000;

    uint32_t m_id = 0;
    uint32_t m_hp = 0;

};

//typedef uint32_t (Unit::* unitMethod)() const;
using unitMethod = uint32_t (Unit::*)() const;

using unitField = uint32_t Unit::*;

void PrintValueByMethod(Unit* unit, unitMethod method)
{
    std::cout << (unit->*method)() << "\n";
    std::cout << (unit->method)() << "\n";
}

void PrintValueByField(Unit* unit, unitField field)
{
    std::cout << unit->*field << "\n";
    std::cout << unit->field << "\n";
}


int main()
{
    Unit unit(1, 100);

    //    PrintValueByMethod(unit, &Unit::id);
    PrintValueByMethod(&unit, &Unit::id);

    PrintValueByField(&unit, &Unit::m_id);
    PrintValueByField(&unit, &Unit::m_hp);

    return util::PrintComplete();
}