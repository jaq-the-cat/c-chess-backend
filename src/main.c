#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"

void make_game() {
    Board board = {0};
    Piece p;
    // make pieces
    Piece pawn = make_piece(Pawn);
    Piece bishop = make_piece(Bishop);
    Piece knight = make_piece(Knight);
    Piece rook = make_piece(Rook);
    Piece queen = make_piece(Queen);
    Piece king = make_piece(King);
    // Pawns
    for (int x=0; x<BOARD_SIZE; x++) {
        set_position(&pawn, White, x);
        board[x + BOARD_SIZE*p.y] = p;
        set_position(&pawn, Black, x);
        board[x + BOARD_SIZE*p.y] = p;
    }
    // Rooks

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
