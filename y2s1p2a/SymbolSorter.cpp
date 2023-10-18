#include "SymbolSorter.h"

void Swap(char& a, char& b)
{
    char c = a;
    a = b;
    b = c;
}

void SymbolSorter::Show(std::vector<char> input)
{
    for (auto iter = input.begin(); iter != input.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void SymbolSorter::Sort(std::vector<char> input, std::vector<char> &inputI, std::vector<char> &inputII)
{
    for (auto iterI = input.begin(); iterI != input.end();)
    {
        bool check = false;
        for (auto iterJ = iterI + 1; iterJ != input.end();)
        {
            if (*iterI == *iterJ)
            {
                iterJ = input.erase(iterJ);
                check = true;
            }
            else
            {
                iterJ++;
            }
        }
        if (check)
        {
            inputII.push_back(*iterI);
            iterI = input.erase(iterI);
        }
        else
        {
            inputI.push_back(*iterI);
            iterI++;
        }
    }
}

int SymbolSorter::Length(std::vector<char>& input)
{
    int length = 0;
    for (char c : input)
    {
        if (isalpha(c)) length++;
    }
    return length;
}

void SymbolSorter::Mirror(std::vector<char> &input)
{
    for (int i = 0; i < input.size() / 2 - 1; ++i)
    {
        Swap(input[i], input[input.size() - 1 - i]);
    }
}

void SymbolSorter::Change(std::vector<char>& input, int i)
{
    try
    {
        std::cout << input[i] << ' ';
    }
    catch (std::out_of_range& e)
    {
        std::cout << "error" << ' ';
    }
}

void SymbolSorter::Destroy(std::vector<char> &input)
{
    try
    {
        //code
    }
    catch (std::exception& e)
    {
        input.clear();
    }
}