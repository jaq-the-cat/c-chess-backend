#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

#define POINT(X, Y) (Point) { X, Y }
#define MOVES(...) { __VA_ARGS__ }

void f() {
    Moves m1 = MOVES(POINT(1, 2), POINT(2, 3));
}
