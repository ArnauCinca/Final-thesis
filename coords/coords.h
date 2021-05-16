#include <stdlib.h>
#include "../misc/misc.h"
#include "../main.h"

#ifndef _coords_h
#define _coords_h

typedef struct coords{
    double x;
#if TRIDIM == 1
    double y;
    double z;	
#endif
} coords;

coords orig();
double dist(coords i, coords j);
void coordsRandomInit(coords* c, double initial_dispersion);
void randomMove(coords* c);

#endif
