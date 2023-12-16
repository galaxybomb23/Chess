// Description: This is a bitboard class header file

#ifndef BITBOARD_HPP
#define BITBOARD_HPP
// Includes

class BitBoard
{

private:
    // Bitboard for the board
    unsigned long long board;

public:
    // Constructor
    BitBoard() : board(0ULL) {}
    BitBoard(unsigned long long board) : board(board) {}

    // Getters
    unsigned long long getBoard() { return board; }
    bool getBit(int index) { return (board >> index) & 1U; }
    int getBitCount() { return __builtin_popcountll(board); }

    // Setters
    void setBoard(unsigned long long board) { this->board = board; }
    void setBit(int index) { board |= (1ULL << index); }

    // others
    void clearBit(int index) { board &= ~(1ULL << index); }
    void toggleBit(int index) { board ^= (1ULL << index); }

    // Operators
    BitBoard operator&(BitBoard other) { return BitBoard(board & other.getBoard()); }
    BitBoard operator|(BitBoard other) { return BitBoard(board | other.getBoard()); }
    BitBoard operator^(BitBoard other) { return BitBoard(board ^ other.getBoard()); }

    // deconstructor
    ~BitBoard() {}
};

#endif // BITBOARD_HPP