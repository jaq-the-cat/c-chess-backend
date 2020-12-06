#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type, PieceTeam team, int x) {
    Piece p = PIECE_C(type);
    p.x = x;
    int y;
    if (team == White)
        y = BOARD_SIZE - 1 - (p.type == Pawn);
    else
        y = 0 + (p.type == Pawn);
    p.y = y;
    return p;
}
