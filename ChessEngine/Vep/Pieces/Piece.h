#pragma once
#include <array>
#include <ColorEnum.h>

class Piece
{
protected:
	bool IsCaptured;
	bool HasEverMoved;
	bool IsHeld;
	ColorEnum Color;
	std::array<char, 2> BoardPosition;
public:
	Piece(ColorEnum color);
	std::array<char, 2> GetBoardPosition() const;
	std::array<char, 2> SetBoardPosition(std::array<char, 2> newPosition);
	virtual void GetPossibleMoves() = 0;
	virtual char GetFenRepresentation() = 0;
	bool BecomeCaptured();
	bool Hold();
	bool Release();
	bool GetIsCaptured() const;
	bool GetHasEverMoved() const;
	bool GetIsHeld() const;
	ColorEnum GetColor() const;
};

