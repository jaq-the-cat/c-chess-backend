#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"

int main() {
    Piece p = make_piece(Queen);
    for (int i=0; i<p.move_len; i++)
        printf("(%d, %d) ", p.moves[i].x, p.moves[i].y);
    return 0;
}
