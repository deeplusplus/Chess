#pragma once
#include <vector>
#include <Pieces/Piece.h>
#include <string>
class Board
{
private:
	std::vector<Piece*> Pieces;
public:
	Board();
	std::vector<Piece*> GetPieces();
	std::string GetBoardAsFenString();
	std::array<std::string, 8> GetBoardAsChars2D();
	std::string ReplaceNumberWithBlanks(std::string fenRow);
};

