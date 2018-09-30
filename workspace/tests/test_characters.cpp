#include "test_characters.h"

#include "../study/classes/character_actions.h"

#include <algorithm>

namespace tests_characters
{

using namespace characters;

void TestCharacters()
{
    srand(time(NULL));

    characters::CharactersList characters;
    const auto charactersCount = 10;

    for (size_t index = 0; index < charactersCount; ++index)
    {
        switch (rand() % 3)
        {
            case 0: characters.push_front(new characters::Worker); break;
            case 1: characters.push_front(new characters::Pirate); break;
            case 2: characters.push_front(new characters::Doctor); break;
        }
    }

    characters::Do(characters);

    std::random_shuffle(std::begin(characters), std::end(characters));
    characters::Do(characters);
}

} // namespace characters