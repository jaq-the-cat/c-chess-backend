#include <stdio.h>
#include <stdlib.h>

#include "game.h"

int is_valid(Board board, int x, int y) {
    return x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE && board[x + BOARD_SIZE*y].type == NoneType;
}

int get_move_len(PieceTypes type) {
    switch (type) {
        case Pawn:
            return PAWN_L;
        case Rook:
            return ROOK_L;
        case Knight:
            return KNIGHT_L;
        case King:
            return KING_L;
        case Queen:
            return QUEEN_L;
        default:
            return 0;
    }
}

void make_game() {
    Board board = {0};

    init_pawns(board);
    init_bi_piece(board, Rook, 0);
    init_bi_piece(board, Knight, 1);
    init_bi_piece(board, Bishop, 2);
    init_s_piece(board, King, 3);
    init_s_piece(board, Queen, 4);

    int sel_x = 1;
    int sel_y = 0;
    Piece *sel;

    // print board
    for (int y=0; y<BOARD_SIZE; y++) {
        for (int x=0; x<BOARD_SIZE; x++) {
            if (x == sel_x && y == sel_y) {
                sel = &board[x + BOARD_SIZE*y];
                printf("S ");
            }
            else
                printf("%d ", board[x + BOARD_SIZE*y].type);
        }
        printf("\n");
    }

    // print moves for selected piece
    for (int m=0; m<get_move_len(sel->type); m++) {
        Point move = POINT(sel->x + KNIGHT_M[m].x, sel->y + KNIGHT_M[m].y);
        if (is_valid(board, move.x, move.y))
            printf("(%d, %d)\n", move.x, move.y);
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

void init_bi_piece(Board board, PieceTypes type, int x) {
    Piece p;

    // left
    p = make_piece(type, White, x);
    board[x + BOARD_SIZE*p.y] = p;

    p = make_piece(type, Black, x);
    board[x + BOARD_SIZE*p.y] = p;

    // right
    p = make_piece(type, White, BOARD_SIZE-1-x);
    board[BOARD_SIZE-1-x + BOARD_SIZE*p.y] = p;

    p = make_piece(type, Black, BOARD_SIZE-1-x);
    board[BOARD_SIZE-1-x + BOARD_SIZE*p.y] = p;
}

void init_s_piece(Board board, PieceTypes type, int x) {
    Piece p;

    // left
    p = make_piece(type, White, x);
    board[x + BOARD_SIZE*p.y] = p;

    p = make_piece(type, Black, x);
    board[x + BOARD_SIZE*p.y] = p;
}
