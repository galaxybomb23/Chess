// desc: Fen class

#ifndef FEN_HPP
#define FEN_HPP

#include <string>
#include <vector>
#include <iostream>

using std::cout;

/// @brief Fen class
/// @details This class is used to store the fen string
class fen
{
public:
    std::string boardFen;
    std::string activeColor;
    std::string castlingRights;
    std::string enPassant;
    std::string halfMoveClock;
    std::string fullMoveNumber;
    std::vector<std::vector<char>> board = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));

    fen(std::string fen)
    {
        // get the encoded board
        boardFen = fen.substr(0, fen.find(' '));
        // cout << "boardFen: " << boardFen << "\n";
        fen.erase(0, fen.find(' ') + 1);

        // get the active color
        activeColor = fen.substr(0, fen.find(' '));
        // cout << "activeColor: " << activeColor << "\n";
        fen.erase(0, fen.find(' ') + 1);

        // get the castling rights
        castlingRights = fen.substr(0, fen.find(' '));
        // cout << "castlingRights: " << castlingRights << "\n";
        fen.erase(0, fen.find(' ') + 1);

        // get the en passant square
        enPassant = fen.substr(0, fen.find(' '));
        // cout << "enPassant: " << enPassant << "\n";
        fen.erase(0, fen.find(' ') + 1);

        // get the half move clock
        halfMoveClock = fen.substr(0, fen.find(' '));
        // cout << "halfMoveClock: " << halfMoveClock << "\n";
        fen.erase(0, fen.find(' ') + 1);

        // get the full move number
        fullMoveNumber = fen.substr(0, fen.find(' '));
        // cout << "fullMoveNumber: " << fullMoveNumber << "\n";
        fen.erase(0, fen.find(' ') + 1);

        // build a board from the fen
        Fen2board();
    }

    void Fen2board();
};

void fen::Fen2board()
{
    int i = 0, j = 0;
    for (auto c : boardFen)
    {
        if (c == '/')
        {
            i++;
            j = 0;
        }
        else if (c >= '1' && c <= '8')
        {
            j += c - '0';
        }
        else
        {
            board[i][j] = c;
            j++;
        }
    }
}

#endif // FEN_HPf