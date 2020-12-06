#ifndef PIECES_H
#define PIECES_H

#define M1 1
#define MINF 2

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }
#define PIECE_C(x, y, type, team) (Piece) { .x = x, .y = y, .type = type, .team = team }

#define BOARD_SIZE 8

#define MOVE_COUNT 8

typedef enum {
    Pawn = 1,
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

typedef Piece Board[BOARD_SIZE*BOARD_SIZE];

Piece make_piece(PieceTypes, PieceTeam, int);

#endif
