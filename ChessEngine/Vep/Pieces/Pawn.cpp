#include "Pawn.h"

void Pawn::GetPossibleMoves()
{
}

Pawn::Pawn(ColorEnum color) : Piece(color)
{
}

char Pawn::GetFenRepresentation()
{
    if (GetColor() == ColorEnum::Black)
        return 'p';
    else
        return 'P';
}
