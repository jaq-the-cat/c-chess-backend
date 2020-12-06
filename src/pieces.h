#ifndef PIECES_H
#define PIECES_H

#define M1 1
#define MINF 2

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }
#define PIECE_C(type, team) (Piece) { .type = type, .team = team }

#define MOVE_COUNT 8

typedef enum {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King,
} PieceTypes;

typedef enum {
    White,
    Black,
} PieceTeam;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    PieceTeam team;

    PieceTypes type;
    Point moves[MOVE_COUNT];
    int move_len;
} Piece;

Piece make_piece(PieceTypes, PieceTeam, int);

#endif
