#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_T(type);
    switch(type) {
        case Pawn: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<3; i++)
                p.moves[i] = m[i];
            break;
        }
        case Bishop: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            break;
        }
        case Knight: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            break;
        }
        case Rook: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            break;
        }
        case Queen: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            break;
        }
        case King: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            break;
        }
    }
    return p;
}
