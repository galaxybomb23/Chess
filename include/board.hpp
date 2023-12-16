// Description: Board class header file

// Includes
#ifndef BOARD_HPP
#define BOARD_HPP
#include "bitBoard.hpp"
#include <iostream>

class Board
{
protected:
    // Bitboards for each piece
    /*
       X  │  A  │  B  │  C  │  D  │  E  │  F  │  G  │  H
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       8  │  56 │  57 │  58 │  59 │  60 │  61 │  62 │  63       <- black
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       7  │  48 │  49 │  50 │  51 │  52 │  53 │  54 │  55
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       6  │  40 │  41 │  42 │  43 │  44 │  45 │  46 │  47
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       5  │  32 │  33 │  34 │  35 │  36 │  37 │  38 │  39
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       4  │  24 │  25 │  26 │  27 │  28 │  29 │  30 │  31
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       3  │  16 │  17 │  18 │  19 │  20 │  21 │  22 │  23
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       2  │   8 │   9 │  10 │  11 │  12 │  13 │  14 │  15
    ──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────
       1  │   0 |   1 |   2 |   3 |   4 |   5 |   6 |   7       <- white

    */
    bool isWhiteTurn = true;
    // white pieces
    BitBoard whitePawns;
    BitBoard whiteKnights;
    BitBoard whiteBishops;
    BitBoard whiteRooks;
    BitBoard whiteQueens;
    BitBoard whiteKing;

    // black pieces
    BitBoard blackPawns;
    BitBoard blackKnights;
    BitBoard blackBishops;
    BitBoard blackRooks;
    BitBoard blackQueens;
    BitBoard blackKing;

public:
    // Constructor for base board
    Board(bool is_base) : whitePawns(0x000000000000FF00ULL), whiteKnights(0x0000000000000042ULL), whiteBishops(0x0000000000000024ULL), whiteRooks(0x0000000000000081ULL), whiteQueens(0x0000000000000008ULL), whiteKing(0x0000000000000010ULL), blackPawns(0x00FF000000000000ULL), blackKnights(0x4200000000000000ULL), blackBishops(0x2400000000000000ULL), blackRooks(0x8100000000000000ULL), blackQueens(0x0800000000000000ULL), blackKing(0x1000000000000000ULL){};
    // Constructor for empty board
    Board() : whitePawns(0ULL), whiteKnights(0ULL), whiteBishops(0ULL), whiteRooks(0ULL), whiteQueens(0ULL), whiteKing(0ULL), blackPawns(0ULL), blackKnights(0ULL), blackBishops(0ULL), blackRooks(0ULL), blackQueens(0ULL), blackKing(0ULL){};

    // generate all possible moves
    void generateMoves();

    // evaluate the board
    int evaluate();

    // Getters
    BitBoard getWhitePawns() { return whitePawns; }
    BitBoard getWhiteKnights() { return whiteKnights; }
    BitBoard getWhiteBishops() { return whiteBishops; }
    BitBoard getWhiteRooks() { return whiteRooks; }
    BitBoard getWhiteQueens() { return whiteQueens; }
    BitBoard getWhiteKing() { return whiteKing; }
    BitBoard getBlackPawns() { return blackPawns; }
    BitBoard getBlackKnights() { return blackKnights; }
    BitBoard getBlackBishops() { return blackBishops; }
    BitBoard getBlackRooks() { return blackRooks; }
    BitBoard getBlackQueens() { return blackQueens; }
    BitBoard getBlackKing() { return blackKing; }

    // Setters
    void setWhitePawns(BitBoard whitePawns) { this->whitePawns = whitePawns; }
    void setWhiteKnights(BitBoard whiteKnights) { this->whiteKnights = whiteKnights; }
    void setWhiteBishops(BitBoard whiteBishops) { this->whiteBishops = whiteBishops; }
    void setWhiteRooks(BitBoard whiteRooks) { this->whiteRooks = whiteRooks; }
    void setWhiteQueens(BitBoard whiteQueens) { this->whiteQueens = whiteQueens; }
    void setWhiteKing(BitBoard whiteKing) { this->whiteKing = whiteKing; }
    void setBlackPawns(BitBoard blackPawns) { this->blackPawns = blackPawns; }
    void setBlackKnights(BitBoard blackKnights) { this->blackKnights = blackKnights; }
    void setBlackBishops(BitBoard blackBishops) { this->blackBishops = blackBishops; }
    void setBlackRooks(BitBoard blackRooks) { this->blackRooks = blackRooks; }
    void setBlackQueens(BitBoard blackQueens) { this->blackQueens = blackQueens; }
    void setBlackKing(BitBoard blackKing) { this->blackKing = blackKing; }

    // others
    void printBoard();

    // deconstructor
    ~Board() {}
};

void Board::printBoard()
{
    std::cout << "   X  │  A  │  B  │  C  │  D  │  E  │  F  │  G  │  H  │" << std::endl;
    std::cout << "──────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "   " << 8 - i << "  │  ";
        for (int j = 0; j < 8; j++)
        {
            if (whitePawns.getBit(i * 8 + j))
            {
                std::cout << "♙  │  ";
            }
            else if (whiteKnights.getBit(i * 8 + j))
            {
                std::cout << "♘  │  ";
            }
            else if (whiteBishops.getBit(i * 8 + j))
            {
                std::cout << "♗  │  ";
            }
            else if (whiteRooks.getBit(i * 8 + j))
            {
                std::cout << "♖  │  ";
            }
            else if (whiteQueens.getBit(i * 8 + j))
            {
                std::cout << "♕  │  ";
            }
            else if (whiteKing.getBit(i * 8 + j))
            {
                std::cout << "♔  │  ";
            }
            else if (blackPawns.getBit(i * 8 + j))
            {
                std::cout << "♟  │  ";
            }
            else if (blackKnights.getBit(i * 8 + j))
            {
                std::cout << "♞  │  ";
            }
            else if (blackBishops.getBit(i * 8 + j))
            {
                std::cout << "♝  │  ";
            }
            else if (blackRooks.getBit(i * 8 + j))
            {
                std::cout << "♜  │  ";
            }
            else if (blackQueens.getBit(i * 8 + j))
            {
                std::cout << "♛  │  ";
            }
            else if (blackKing.getBit(i * 8 + j))
            {
                std::cout << "♚  │  ";
            }
            else
            {
                std::cout << "   │  ";
            }
        }
        std::cout << std::endl;
    }
};

#endif // BOARD_HPP