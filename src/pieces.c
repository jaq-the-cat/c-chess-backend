#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_T(type);
    switch(type) {
        case Pawn:
            //Point m[MOVE_COUNT] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            //for (int i=0; i<MOVE_COUNT; i++);
            break;
        case Bishop:
            break;
        case Knight:
            break;
        case Rook:
            break;
        case Queen:
            break;
        case King:
            break;
    }
    return p;
}
