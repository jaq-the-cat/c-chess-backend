#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_T(type);
    switch(type) {
        case Pawn: {
            const int moves = 3;
            const Point m[MOVE_COUNT] = MOVES(POINT(M1, 0), POINT(-M1, 0), POINT(0, M1));
            for (int i=0; i<moves; i++)
                p.moves[i] = m[i];
            p.move_len = moves;
            break;
        }
        case Bishop: {
            const int moves = 4;
            const Point m[MOVE_COUNT] = MOVES(POINT(MINF, MINF), POINT(-MINF, -MINF), POINT(MINF, -MINF),
                    POINT(-MINF, MINF));
            for (int i=0; i<moves; i++)
                p.moves[i] = m[i];
            p.move_len = moves;
            break;
        }
        case Knight: {
            const int moves = 3;
            const Point m[MOVE_COUNT] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<moves; i++)
                p.moves[i] = m[i];
            p.move_len = moves;
            break;
        }
        case Rook: {
            const int moves = 4;
            const Point m[MOVE_COUNT] = MOVES(POINT(MINF, 0), POINT(-MINF, 0), POINT(0, MINF), POINT(0, -MINF));
            for (int i=0; i<moves; i++)
                p.moves[i] = m[i];
            p.move_len = moves;
            break;
        }
        case Queen: {
            const int moves = 8;
            const Point m[MOVE_COUNT] = MOVES(
                    POINT(-MINF,  MINF), POINT(0,  MINF), POINT(MINF,  MINF),
                    POINT(-MINF,  0),                     POINT(MINF,  0),
                    POINT(-MINF, -MINF), POINT(0, -MINF), POINT(MINF, -MINF),
            );
            for (int i=0; i<moves; i++)
                p.moves[i] = m[i];
            p.move_len = moves;
            break;
        }
        case King: {
            const int moves = 8;
            const Point m[MOVE_COUNT] = MOVES(
                    POINT(-M1,  M1), POINT(0,  M1), POINT(M1,  M1),
                    POINT(-M1,  0),                 POINT(M1,  0),
                    POINT(-M1, -M1), POINT(0, -M1), POINT(M1, -M1),
            );
            for (int i=0; i<moves; i++)
                p.moves[i] = m[i];
            p.move_len = moves;
            break;
        }
    }
    return p;
}
