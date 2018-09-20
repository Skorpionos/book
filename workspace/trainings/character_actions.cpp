#include "character_actions.h"

namespace characters
{

void Do(CharactersList characters)
{
    std::cout << "\n" << "We are ready to act:" << "\n"
              << "====================" << "\n";
    for (const auto& person : characters)
        person->Act();
}

} // namespace characters