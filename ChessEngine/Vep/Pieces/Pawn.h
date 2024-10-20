#pragma once
#include "Piece.h"

class Pawn :
    public Piece
{
public:
    void GetPossibleMoves() override;
    Pawn(ColorEnum color);
    char GetFenRepresentation() override;
};

