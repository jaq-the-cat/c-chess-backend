#ifndef PIECES_H
#define PIECES_H

#define MINF -1

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }
#define PIECE_C(type) (Piece) { 0, 0, NoneTeam, type }

#define MOVE_COUNT 8

#define PAWN_L 3
#define BISHOP_L 4
#define KNIGHT_L 8
#define ROOK_L 4
#define QUEEN_L 8
#define KING_L 8

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    NoneType,
    Pawn,
    Rook,
    Knight,
    Bishop,
    King,
    Queen,
} PieceTypes;

typedef enum {
    NoneTeam,
    White,
    Black,
} PieceTeam;

typedef struct {
    int x;
    int y;
    PieceTeam team;
    PieceTypes type;
} Piece;

typedef const Point Moves[MOVE_COUNT];

Piece make_piece(PieceTypes, PieceTeam, int);

// Moves
static Moves PAWN_M = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));

static Moves ROOK_M = MOVES(POINT(MINF, 0), POINT(-MINF, 0), POINT(0, MINF), POINT(0, -MINF));

static Moves KNIGHT_M = MOVES(
        // left
        POINT( 2,  1), POINT( 2, -1), 
        // right
        POINT(-2,  1), POINT(-2, -1), 
        // up
        POINT(-1,  2), POINT( 1,  2), 
        // down
        POINT(-1, -2), POINT( 1, -2));

static Moves BISHOP_M = MOVES(POINT(MINF, MINF), POINT(-MINF, -MINF), POINT(MINF, -MINF),
        POINT(-MINF, MINF));

static Moves QUEEN_M = MOVES(
        POINT(-MINF,  MINF), POINT(0,  MINF), POINT(MINF,  MINF),
        POINT(-MINF,  0),                     POINT(MINF,  0),
        POINT(-MINF, -MINF), POINT(0, -MINF), POINT(MINF, -MINF));

static Moves KING_M = MOVES(
        POINT(-1,  1), POINT(0,  1), POINT(1,  1),
        POINT(-1,  0),                 POINT(1,  0),
        POINT(-1, -1), POINT(0, -1), POINT(1, -1));

#endif
