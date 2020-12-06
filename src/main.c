#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"

void make_game() {
    Board board = {0};
    Piece p;
    // Pawns
    for (int x=0; x<BOARD_SIZE; x++) {
        p = make_piece(Pawn, White, x);
        board[x + BOARD_SIZE*p.y] = p;

        p = make_piece(Pawn, Black, x);
        board[x + BOARD_SIZE*p.y] = p;
    }

    // Rooks
    // left
    p = make_piece(Rook, White, 0);
    board[0 + BOARD_SIZE*p.y] = p;

    p = make_piece(Rook, Black, BOARD_SIZE-1);
    board[BOARD_SIZE-1 + BOARD_SIZE*p.y] = p;

    // right
    p = make_piece(Pawn, White, 0);
    board[0 + BOARD_SIZE*p.y] = p;

    p = make_piece(Pawn, Black, BOARD_SIZE-1);
    board[BOARD_SIZE-1 + BOARD_SIZE*p.y] = p;

    for (int y=0; y<BOARD_SIZE; y++) {
        for (int x=0; x<BOARD_SIZE; x++)
            printf("%d ", board[x + BOARD_SIZE*y].type);
        printf("\n");
    }
}

int main() {
    make_game();
    return 0;
}
