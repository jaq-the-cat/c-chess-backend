#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_C(type);
    get_moves_for(&p);
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

void get_moves_for(Piece *p) {
    int moves = 0;
    switch(p->type) {
        case Pawn: {
            moves = 3;
            const Point m[MOVE_COUNT] = MOVES(POINT(M1, 0), POINT(-M1, 0), POINT(0, M1));
            for (int i=0; i<moves; i++)
                p->moves[i] = m[i];
            break;
        }
        case Bishop: {
            moves = 4;
            const Point m[MOVE_COUNT] = MOVES(POINT(MINF, MINF), POINT(-MINF, -MINF), POINT(MINF, -MINF),
                    POINT(-MINF, MINF));
            for (int i=0; i<moves; i++)
                p->moves[i] = m[i];
            break;
        }
        case Knight: {
            moves = 3;
            const Point m[MOVE_COUNT] = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
            for (int i=0; i<moves; i++)
                p->moves[i] = m[i];
            break;
        }
        case Rook: {
            moves = 4;
            const Point m[MOVE_COUNT] = MOVES(POINT(MINF, 0), POINT(-MINF, 0), POINT(0, MINF), POINT(0, -MINF));
            for (int i=0; i<moves; i++)
                p->moves[i] = m[i];
            break;
        }
        case Queen: {
            moves = 8;
            const Point m[MOVE_COUNT] = MOVES(
                    POINT(-MINF,  MINF), POINT(0,  MINF), POINT(MINF,  MINF),
                    POINT(-MINF,  0),                     POINT(MINF,  0),
                    POINT(-MINF, -MINF), POINT(0, -MINF), POINT(MINF, -MINF),
            );
            for (int i=0; i<moves; i++)
                p->moves[i] = m[i];
            break;
        }
        case King: {
            moves = 8;
            const Point m[MOVE_COUNT] = MOVES(
                    POINT(-M1,  M1), POINT(0,  M1), POINT(M1,  M1),
                    POINT(-M1,  0),                 POINT(M1,  0),
                    POINT(-M1, -M1), POINT(0, -M1), POINT(M1, -M1),
            );
            for (int i=0; i<moves; i++)
                p->moves[i] = m[i];
            break;
        }
        default:
            break;
    }
    p->move_len = moves;
}
