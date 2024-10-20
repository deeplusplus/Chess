#include "Board.h"
#include <sstream>
#include <Pieces/Pawn.h>

Board::Board()
{
    Pawn pawn = Pawn(ColorEnum::White);
    pawn.SetBoardPosition({'a', '2'});
}

std::vector<Piece*> Board::GetPieces()
{
    return Pieces;
}

std::string Board::GetBoardAsFenString()
{
    return "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
}

std::array<std::string, 8> Board::GetBoardAsChars2D()
{
    std::array<std::string, 8> board;

    std::stringstream stringStream(GetBoardAsFenString());
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(stringStream, segment, '/'))
    {
        seglist.push_back(segment);
    }

    for (int row = 0; row <= 7; row++)
    {
        std::string fenRow = seglist[row];
        board[row] = ReplaceNumberWithBlanks(fenRow);
    }

    return board;
};

std::string Board::ReplaceNumberWithBlanks(std::string fenRow)
{
    std::string newFenRow;

    for (size_t character = 0; character < fenRow.size(); character++)
    {
        switch (fenRow[character])
        {
        case('1'):
            newFenRow += "_";
            break;
        case('2'):
            newFenRow += "__";
            break;
        case('3'):
            newFenRow += "___";
            break;
        case('4'):
            newFenRow += "____";
            break;
        case('5'):
            newFenRow += "_____";
            break;
        case('6'):
            newFenRow += "_______";
            break;
        case('7'):
            newFenRow += "_______";
            break;
        case('8'):
            newFenRow += "________";
            break;
        default:
            newFenRow += fenRow[character];
        }
    }

    return newFenRow;
}
