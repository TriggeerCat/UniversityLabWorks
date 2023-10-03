#ifndef Y2S1P2A_SYMBOLSORTER_H
#define Y2S1P2A_SYMBOLSORTER_H
#include <iostream>
#include <vector>
#include <string>

class SymbolSorter {
public:
    static void Show(std::vector<char> input);
    static void Sort(std::vector<char> input, std::vector<char> &inputI, std::vector<char> &inputII);
    static int Length(std::vector<char>& input); //Довжина, к-ть символів
    static void Mirror(std::vector<char>& input); //Віддзеркалити
    static void Change(std::vector<char>& input, int i); //і-тий елемент
    static void Destroy(std::vector<char>& input); //знищити список
};


#endif //Y2S1P2A_SYMBOLSORTER_H
