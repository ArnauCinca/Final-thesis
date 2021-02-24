#include "coords.h"
#include <math.h>




double dist(coords i, coords j){
	double dx = i.x-j.x;
#ifdef TRIDIM
	double dy = i.y-j.y;
	double dz = i.z-j.z;
	return sqrt(dx*dx +dy*dy + dz*dz);
#else
	return abs(dx);
#endif
}




void coordsRandomInit(coords* c, double initial_dispersion){
	c->x = randomInRange(-initial_dispersion,initial_dispersion);
#ifdef TRIDIM

#endif
}

void randomMove(coords* c){
	c->x += randomInRange(-1,1);
#ifdef TRIDIM

#endif
}
