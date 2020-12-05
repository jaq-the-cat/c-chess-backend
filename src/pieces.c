#include "pieces.h"

#include <stdio.h>
#include <stdlib.h>

#define point(x, y) (Point) { x, y }
#define moves(...) { __VA_ARGS__ }

void f() {
    Moves m1 = moves(point(1, 2), point(2, 3));
    printf("%d", m1[0].x);
    printf("%d", m1[1].x);
}
