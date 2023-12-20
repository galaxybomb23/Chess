
#include <string>
#include <iostream>
#include <vector>

using std::cout;

void print2dboard(const std::vector<std::vector<char>> &board)
{
    cout << "Fen board: \n";
    for (auto i : board)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
