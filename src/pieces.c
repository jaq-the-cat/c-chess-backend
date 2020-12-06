#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_C(type);
    return p;
}

void set_position(Piece *p, PieceTeam team, int x) {
    p->x = x;
    int y;
    if (team == White)
        y = BOARD_SIZE - 1 - (p->type == Pawn);
    else
        y = 0 + (p->type == Pawn);
    p->y = y;
}
