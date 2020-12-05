#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_T(type);
    switch(type) {
        case Pawn: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(M1, 0), POINT(-M1, 0), POINT(0, M1));
            for (int i=0; i<3; i++)
                p.moves[i] = m[i];
            p.move_len = MOVES;
            break;
        }
        case Bishop: {
            const int MOVES = 4;
            Point m[MOVES] = MOVES(POINT(MINF, MINF), POINT(-MINF, -MINF), POINT(MINF, -MINF),
                    POINT(-MINF, MINF));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            p.move_len = MOVES;
            break;
        }
        case Knight: {
            const int MOVES = 3;
            Point m[MOVES] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            p.move_len = MOVES;
            break;
        }
        case Rook: {
            const int MOVES = 4;
            Point m[MOVES] = MOVES(POINT(MINF, 0), POINT(-MINF, 0), POINT(0, MINF), POINT(0, -MINF));
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            p.move_len = MOVES;
            break;
        }
        case Queen: {
            const int MOVES = 8;
            Point m[MOVES] = MOVES(
                    POINT(-MINF,  MINF), POINT(0,  MINF),  POINT(MINF,  MINF),
                    POINT(-MINF,  0),                POINT(MINF,  0),
                    POINT(-MINF, -MINF), POINT(0, -MINF),  POINT(MINF, -MINF),
            );
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            p.move_len = MOVES;
            break;
        }
        case King: {
            const int MOVES = 8;
            Point m[MOVES] = MOVES(
                    POINT(-M1,  M1), POINT(0,  M1),  POINT(M1,  M1),
                    POINT(-M1,  0),                POINT(M1,  0),
                    POINT(-M1, -M1), POINT(0, -M1),  POINT(M1, -M1),
            );
            for (int i=0; i<MOVES; i++)
                p.moves[i] = m[i];
            p.move_len = MOVES;
            break;
        }
    }
    return p;
}
