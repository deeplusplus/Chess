#include "Piece.h"

Piece::Piece(ColorEnum color)
{
	Color = color;
	IsCaptured = false;
	HasEverMoved = false;
	IsHeld = false;
	BoardPosition = {' ', ' '};
}

std::array<char, 2> Piece::GetBoardPosition() const
{
	return BoardPosition;
}

std::array<char, 2> Piece::SetBoardPosition(std::array<char, 2> newPosition)
{
	HasEverMoved = true;
	BoardPosition = newPosition;
	return BoardPosition;
}

bool Piece::BecomeCaptured()
{
	IsCaptured = true;
	return IsCaptured;
}

bool Piece::Hold()
{
	IsHeld = true;
	return true;
}

bool Piece::Release()
{
	IsHeld = false;
	return false;
}

bool Piece::GetIsCaptured() const
{
	return IsCaptured;
}

bool Piece::GetHasEverMoved() const
{
	return HasEverMoved;
}

bool Piece::GetIsHeld() const
{
	return IsHeld;
}

ColorEnum Piece::GetColor() const
{
	return Color;
}

