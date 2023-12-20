#include "board.hpp"
#include "testutils.hpp"

int main()
{
    // generate a fen
    fen Fen("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    // print2dboard(Fen.board);

    // generate standard board
    // Board board(true);
    // board.printBoard();

    // generate board from fen
    Board Fboard(Fen);
    Fboard.printBoard();

    return 0;
}