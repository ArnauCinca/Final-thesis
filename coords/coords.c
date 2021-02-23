#include "coords.h"
#include <math.h>




double dist(coords i, coords j){
	double dx = i.x-j.x;
//#ifdef tri_dim
//	double dy = 0;
//	double dz = 0;
//	return sqrt(dx*dx +dy*dy + dz*dz);
//#else
	return abs(dx);
//#endif
}




void coordsRandomInit(coords* c, double initial_dispersion){
	c->x = randomInRange(-initial_dispersion,initial_dispersion);
//#ifdef tri_dim

//#endif
}

void randomMove(coords* c){
	c->x += randomInRange(-1,1);
//#ifdef tri_dim

//#endif
}
