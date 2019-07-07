Person maria            = {"Maria", 100};
Person olga             = {"Olga", 100};
Person nikolay          = {"Nikolay", 200};
Person petr             = {"Petr", 15};
Person tatiana          = {"Tatiana", 15};
Person petr_sergeevich  = {"Petr", 15};

std::vector<Person> people = {maria, olga, nikolay, petr, tatiana, petr_sergeevich};

template <class T>
inline bool IsInRange(T value, std::pair<T, T> range)
{
    const auto [min, max] = range;
    return (value >= min && value <= max);
}

auto test()
{
    return std::tuple<int, int>(2, 3);
}

const auto time0 = std::chrono::steady_clock::now();

std::vector<int> list(100000000);

const auto time1 = SolveDeltaTime(time0);

std::iota(list.begin(), list.end(), 1);

const auto time2 = SolveDeltaTime(time1);
std::cout << "--------------" << "\n";
const auto time3 = SolveDeltaTime(time0);

    auto result = test();
std::cout << std::get<0>(result) << "\n";
std::cout << std::get<1>(result) << "\n";


for (const auto brace : {isOpen, isClosed})