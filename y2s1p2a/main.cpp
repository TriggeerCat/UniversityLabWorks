#include <iostream>
#include <vector>
#include <string>
#include "SymbolSorter.h"

int main()
{
    std::string input = "Artem is balab, not aaaa arab!";
    std::vector<char> victor;
    std::vector<char> victorI;
    std::vector<char> victorII;

    victor.reserve(input.size()); victorI.reserve(input.size()); victorII.reserve(input.size());

    for (char i : input)
        victor.push_back(i);

    SymbolSorter::Sort(victor, victorI, victorII);

    SymbolSorter::Show(victorI);
    SymbolSorter::Show(victorII);

    std::cout << SymbolSorter::Length(victor) << " " << SymbolSorter::Length(victorI) << std::endl;

    SymbolSorter::Show(victor);
    SymbolSorter::Mirror(victor);
    SymbolSorter::Show(victor);

    return 0;
}