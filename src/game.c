#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void make_game() {
    Board board = {0};

    init_pawns(board);
    init_rooks(board);

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

void init_rooks(Board board) {
    Piece p;

    // left
    p = make_piece(Rook, White, 0);
    board[0 + BOARD_SIZE*p.y] = p;

    p = make_piece(Rook, Black, BOARD_SIZE-1);
    board[0 + BOARD_SIZE*p.y] = p;

    // right
    p = make_piece(Rook, White, 0);
    board[BOARD_SIZE-1 + BOARD_SIZE*p.y] = p;

    p = make_piece(Rook, Black, BOARD_SIZE-1);
    board[BOARD_SIZE-1 + BOARD_SIZE*p.y] = p;
}

void init_bishops(Board board) {
    Piece p;

    // left
    p = make_piece(Bishop, White, 2);
    board[0 + BOARD_SIZE*p.y] = p;

    p = make_piece(Bishop, Black, BOARD_SIZE-1);
    board[0 + BOARD_SIZE*p.y] = p;

    // right
    p = make_piece(Bishop, White, 0);
    board[BOARD_SIZE-1-2 + BOARD_SIZE*p.y] = p;

    p = make_piece(Bishop, Black, BOARD_SIZE-1);
    board[BOARD_SIZE-1-2 + BOARD_SIZE*p.y] = p;
}
