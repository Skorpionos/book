std::cout << "S T R | B A" << "\n";
for (bool S : {false, true})
for (bool T : {false, true})
for (bool R : {false, true})
{
    auto temp = !(T or R);
    auto B = !S and temp;
    auto A = temp or R;

    std::cout << S << " " << T << " "  << R << " | "  << B << " " << A << "\n";

}
