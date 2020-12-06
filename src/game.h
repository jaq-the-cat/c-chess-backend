#ifndef GAME_H
#define GAME_H

#include "pieces.h"
#include "board.h"

void make_game();

void init_pawns(Board);
void init_bi_piece(Board, PieceTypes, int);

#endif
