#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void make_game() {
    Board board = {0};

    init_pawns(board);
    init_bi_piece(board, Rook, 0);
    init_bi_piece(board, Knight, 1);
    init_bi_piece(board, Bishop, 2);

    // print board
    for (int y=0; y<BOARD_SIZE; y++) {
        for (int x=0; x<BOARD_SIZE; x++)
            printf("%d ", board[x + BOARD_SIZE*y].type);
        printf("\n");
    }
}

void init_pawns(Board board) {
    Piece p;

    for (int x=0; x<BOARD_SIZE; x++) {
        p = make_piece(Pawn, White, x);
        board[x + BOARD_SIZE*p.y] = p;

        p = make_piece(Pawn, Black, x);
        board[x + BOARD_SIZE*p.y] = p;
    }
}

void init_bi_piece(Board board, PieceTypes type, int xoff) {
    Piece p;

    // left
    p = make_piece(type, White, xoff);
    board[xoff + BOARD_SIZE*p.y] = p;

    p = make_piece(type, Black, xoff);
    board[xoff + BOARD_SIZE*p.y] = p;

    // right
    p = make_piece(type, White, BOARD_SIZE-1-xoff);
    board[BOARD_SIZE-1-xoff + BOARD_SIZE*p.y] = p;

    p = make_piece(type, Black, BOARD_SIZE-1-xoff);
    board[BOARD_SIZE-1-xoff + BOARD_SIZE*p.y] = p;
}
