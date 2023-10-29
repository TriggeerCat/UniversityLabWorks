#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

class Array
{
private:
    std::vector<int> arr;
public:
    Array()
    {
        arr = {};
    }

    void CompleteTask(int& positive, int& negative, int& zero)
    {
        for (auto iter = arr.begin(); iter != arr.end(); iter++)
        {
            if (*iter > 0)
                positive++;
            else if (*iter < 0)
                negative++;
            else
                zero++;
        }
    }

    void ReadData()
    {
        std::ifstream read("xread.txt");
        if (read.is_open()) {
            arr.clear();
            copy(std::istream_iterator<int>(read), std::istream_iterator<int>(), back_inserter(arr));
            read.close();
        }
        else {
            std::cerr << "Reading failed." << std::endl;
        }
    }

    void WriteData()
    {
        std::ofstream write("xwrite.txt");
        if (write.is_open()) {
            int positive = 0, negative = 0, zero = 0;
            CompleteTask(positive, negative, zero);
            copy(arr.begin(), arr.end(), std::ostream_iterator<int>(write, " "));
            write << std::endl << "Positives: " << positive << std::endl << "Negatives: " << negative << std::endl << "Zeros: " << zero << std::endl << "Artem is balab, not aaaa arab" << std::endl;
            write.close();
        }
        else {
            std::cerr << "Writing failed." << std::endl;
        }
    }
};

int main()
{
    Array arr;
    arr.ReadData();
    arr.WriteData();
}

//Визначити кількість від'ємних, додатних та нульових елементів одномірного масиву.