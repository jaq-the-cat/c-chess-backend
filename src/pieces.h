#ifndef PIECES_H
#define PIECES_H

#define M1 1
#define MINF 2

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }
#define PIECE_T(type) (Piece) { .type = type }

#define MOVE_COUNT 8

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

typedef struct {
    int x;
    int y;
    PieceTypes type;
    int move_len;
    Point moves[MOVE_COUNT];
} Piece;

Piece make_piece(PieceTypes);

#endif
