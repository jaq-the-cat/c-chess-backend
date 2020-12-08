#ifndef GAME_H
#define GAME_H

#include "pieces.h"
#include "board.h"

void make_game();

int move(Board, Piece*, int, int);

void init_pawns(Board);
void init_bi_piece(Board, PieceTypes, int);
void init_s_piece(Board, PieceTypes, int);

#endif
