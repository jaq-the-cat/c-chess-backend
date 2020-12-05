#ifndef PIECES_H
#define PIECES_H

#define MOVE_1 1
#define MOVE_INF 2

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
    Point from_origin[];
} Moves;

typedef struct {
    int x;
    int y;
    PieceTypes type;
} Piece;

#endif
