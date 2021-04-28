#include <stdlib.h>
#include "../misc/misc.h"

#define TRIDIM 0  //0 1D; 1 3D
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
