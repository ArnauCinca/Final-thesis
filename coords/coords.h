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

// returns a coordinates that are right at the origin {0} ({0,0,0} in three-dimensions).
coords orig();

// returns the euclidean distance between two particles (i and j).
double dist(coords i, coords j);

// initiate the coordinates c with a random value between -initial_dispersion and initial_dispersion.
void coordsRandomInit(coords* c, double initial_dispersion);

// moves the particle c increasing (or decreasing) its values with a random number.
void randomMove(coords* c);

#endif
