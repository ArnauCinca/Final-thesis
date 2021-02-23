#include <stdlib.h>
#include "../misc/misc.h"

//#define tri_dim 1
typedef struct coords{
    double x;
//#ifdef tri_dim
//	double y;
//	double z;	
//#endif
} coords;

double dist(coords i, coords j);
void coordsRandomInit(coords* c, double initial_dispersion);
void randomMove(coords* c);
