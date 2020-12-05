#ifndef PIECES_H
#define PIECES_H

#define MOVE_1 1
#define MOVE_INF 2

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }
#define PIECE_T(type) (Piece) { .type = type }

typedef enum {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King,
} PieceTypes;

typedef struct {
    int x;
    int y;
} Point;

typedef Point Moves[];

typedef struct {
    int x;
    int y;
    PieceTypes type;
} Piece;

Piece make_piece(PieceTypes type) {
    Piece p = PIECE_T(type);
    switch(type) {
        case Pawn:
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

#endif
