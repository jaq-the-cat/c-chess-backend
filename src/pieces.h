#ifndef PIECES_H
#define PIECES_H

#define M1 1
#define MINF 2

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }
#define PIECE_C(type) (Piece) { 0, 0, NoneTeam, type }

#define BOARD_SIZE 8

#define MOVE_COUNT 8

typedef enum {
    NoneType,
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King,
} PieceTypes;

typedef enum {
    NoneTeam,
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
} Piece;

typedef const Point Moves[MOVE_COUNT];

typedef Piece Board[BOARD_SIZE*BOARD_SIZE];

Piece make_piece(PieceTypes);
void set_position(Piece*, PieceTeam, int);

// Moves
static Moves PAWN_M = MOVES(POINT(M1, 0), POINT(-M1, 0), POINT(0, M1));
static const int PAWN_L = 3;

static Moves BISHOP_M = MOVES(POINT(MINF, MINF), POINT(-MINF, -MINF), POINT(MINF, -MINF),
        POINT(-MINF, MINF));
static const int BISHOP_L = 4;

static Moves KNIGHT_M = MOVES(POINT(1, 0), POINT(-1, 0), POINT(0, 1));
static const int KNIGHT_L = 3;

static Moves ROOK_M = MOVES(POINT(MINF, 0), POINT(-MINF, 0), POINT(0, MINF), POINT(0, -MINF));
static const int ROOK_L = 4;

static Moves QUEEN_M = MOVES(
        POINT(-MINF,  MINF), POINT(0,  MINF), POINT(MINF,  MINF),
        POINT(-MINF,  0),                     POINT(MINF,  0),
        POINT(-MINF, -MINF), POINT(0, -MINF), POINT(MINF, -MINF));
static const int QUEEN_L = 8;

static Moves KING_M = MOVES(
        POINT(-M1,  M1), POINT(0,  M1), POINT(M1,  M1),
        POINT(-M1,  0),                 POINT(M1,  0),
        POINT(-M1, -M1), POINT(0, -M1), POINT(M1, -M1));
static const int KING_L = 8;

#endif
