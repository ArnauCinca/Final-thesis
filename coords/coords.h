#include <stdlib.h>
#include "../misc/misc.h"

typedef struct coords{
    double x;
} coords;

double dist(coords i, coords j);
coords coordsRandomInit();
void randomMove(coords* c);
