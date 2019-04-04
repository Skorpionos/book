#include "../internal/io.h"

#include <iostream>
#include <iomanip>

void PrintListOfTypes()
{
    using std::cout;
    using std::setw;

    util::ShowType<uint8_t>();
    util::ShowType<uint16_t>();
    util::ShowType<uint32_t>();
    util::ShowType<uint64_t>();
    util::ShowType<size_t>();

    util::ShowType(true);
    util::ShowType('a');
    util::ShowType("");
    util::ShowType("a");
    util::ShowType("aaaaaaa");
    util::ShowType(1);
    util::ShowType(1u);
    util::ShowType(1l);
    util::ShowType(1ul);
    util::ShowType(1ll);
    util::ShowType(1ull);
    util::ShowType(1.0f);
    util::ShowType(1.0);

    //    cout << setw(25)   << "void"                   << sizeof(void)                   << "\n";

    cout << std::left;
    cout << setw(25)   << "bool"                   << sizeof(bool)                   << "\n";
    cout << setw(25)   << "char"                   << sizeof(char)                   << "\n";
    cout << setw(25)   << "unsigned char"          << sizeof(unsigned char)          << "\n";
    cout << setw(25)   << "signed char"            << sizeof(signed char)            << "\n";
    cout << setw(25)   << "short int"              << sizeof(short int)              << "\n";
    cout << setw(25)   << "unsigned short int"     << sizeof(unsigned short int)     << "\n";
    cout << setw(25)   << "int"                    << sizeof(int)                    << "\n";
    cout << setw(25)   << "unsigned int"           << sizeof(unsigned int)           << "\n";
    cout << setw(25)   << "long int"               << sizeof(long int)               << "\n";
    cout << setw(25)   << "unsigned long int"      << sizeof(unsigned long int)      << "\n";
    cout << setw(25)   << "long long int"          << sizeof(long long int)          << "\n";
    cout << setw(25)   << "unsigned long long int" << sizeof(unsigned long long int) << "\n";
    cout << setw(25)   << "float"                  << sizeof(float)                  << "\n";
    cout << setw(25)   << "double"                 << sizeof(double)                 << "\n";
    cout << setw(25)   << "uint8_t"                << sizeof(uint8_t)                << "\n";
    cout << setw(25)   << "uint16_t"               << sizeof(uint16_t)               << "\n";
    cout << setw(25)   << "uint32_t"               << sizeof(uint32_t)               << "\n";
    cout << setw(25)   << "uint64_t"               << sizeof(uint64_t)               << "\n";
    cout << setw(25)   << "size_t"                 << sizeof(size_t)                 << "\n";
}