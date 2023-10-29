#include <iostream>
#include <vector>

class Tasque {
private:
    std::vector<std::vector<char>> battlefield;

    void SetCross(int row, int col)
    {
        row--;
        col--;
        bool is_set = false;
        while(!is_set)
        {
            if (battlefield[row][col] == ' ')
            {
                battlefield[row][col] = 'x';
                is_set = true;
            }
            else
            {
                std::cout << "This place is already taken. Enter row and col: " << std::endl;
                std::cin >> row >> col;
            }
        }

    }

    bool SetCircle()
    {
        static int turn = 1;
        if (turn == 5)
        {
            print();
            std::cout << "Draw!" << std::endl;
            return true;
        }
        srand(time(nullptr));
        bool is_set = false;
        while(!is_set)
        {
            int row = rand() % 3;
            int col = rand() % 3;
            if (battlefield[row][col] == ' ')
            {
                battlefield[row][col] = 'o';
                is_set = true;
            }
        }
        turn++;
        return false;
    }

    bool WinCheck()
    {
    for (int i = 0; i < 3; i++)
        {
            if (battlefield[i][0] == battlefield[i][1] && battlefield[i][1] == battlefield[i][2] && battlefield[i][0] != ' ')
            {
                std::cout << battlefield[i][0] << " wins!" << std::endl;
                return true;
            }
            if (battlefield[0][i] == battlefield[1][i] && battlefield[1][i] == battlefield[2][i] && battlefield[0][i] != ' ')
            {
                std::cout << battlefield[0][i] << " wins!" << std::endl;
                return true;
            }
            if (battlefield[0][0] == battlefield[1][1] && battlefield[1][1] == battlefield[2][2] && battlefield[0][0] != ' ')
            {
                std::cout << battlefield[0][0] << " wins!" << std::endl;
                return true;
            }
            if (battlefield[0][2] == battlefield[1][1] && battlefield[1][1] == battlefield[2][0] && battlefield[0][2] != ' ')
            {
                std::cout << battlefield[0][2] << " wins!" << std::endl;
                return true;
            }
        }
        return false;
    }

public:
    Tasque()
    {
        battlefield = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    }

    void print()
    {
        for (auto col : battlefield) {
            for (auto row : col) {
                std::cout << row << " ";
            }
            std::cout << std::endl;
        }
    }

    void play()
    {
        while (true)
        {
            int row, col;
            std::cout << "Enter row and col:" << std::endl;
            std::cin >> row >> col;
            SetCross(row, col);
            if (SetCircle()) break;
            print();
            if (WinCheck()) break;
        }
    }
};

int main()
{
    Tasque game1;
    game1.play();
}
