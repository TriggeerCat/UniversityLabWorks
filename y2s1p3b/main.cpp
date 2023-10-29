#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

class Matrix
{
private:
    std::vector<std::vector<int>> matrix;
public:
    Matrix()
    {
        matrix = {};
    }

    int CompleteTask()
    {
        int a = 0;
        int b = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (i > j)
                    a += matrix[i][j];
                else if (i < j)
                    b += matrix[i][j];
            }
        }

        return a * b;
    }

    void ReadFile() {
        std::ifstream read("xread.txt");
        if (read.is_open()) {
            matrix.clear();
            std::string line;
            while (getline(read, line)) {
                std::istringstream iss(line);
                std::vector<int> Row;
                copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), back_inserter(Row));
                matrix.push_back(Row);
            }
            read.close();
        }
        else {
            std::cerr << "Reading failed." << std::endl;
        }
    }

    void WriteFile() {
        std::ofstream write("xwrite.txt");
        if (write.is_open()) {
            for (auto row = matrix.begin(); row != matrix.end(); row++) {
                copy(row->begin(), row->end(), std::ostream_iterator<int>(write, " "));
                write << std::endl;
            }
            write << std::endl << "C = " << CompleteTask() << std::endl;
            write.close();
        }
        else {
            std::cerr << "Failed to open the FILE for writing." << std::endl;
        }
    }
};

int main()
{
    Matrix matrix;
    matrix.ReadFile();
    matrix.WriteFile();
    return 0;
}

//Обчислити добуток С=А*В, де А - сума всіх елементів під головною діагоналлю двохвимірного масиву, а В - сума всіх елементів над головною діагоналлю.