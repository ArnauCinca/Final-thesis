#include "coords.h"
#include <math.h>




double dist(coords i, coords j){
	double dx = i.x-j.x;
#if TRIDIM == 1
	double dy = i.y-j.y;
	double dz = i.z-j.z;
	return sqrt(dx*dx +dy*dy + dz*dz);
#else
	return fabs(dx);
#endif
}




void coordsRandomInit(coords* c, double initial_dispersion){
	c->x = randomInRange(-initial_dispersion,initial_dispersion);
#if TRIDIM == 1
	c->y = randomInRange(-initial_dispersion,initial_dispersion);
	c->z = randomInRange(-initial_dispersion,initial_dispersion);
	
#endif
}

void randomMove(coords* c){
	c->x += randomInRange(-1,1);
#if TRIDIM == 1
	c->y += randomInRange(-1,1);
	c->z += randomInRange(-1,1);
#endif
}
