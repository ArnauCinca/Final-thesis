#include "coords.h"
#include <math.h>



coords orig(){
	coords c;
	c.x = 0.0;
#if TRIDIM == 1
	c.y = 0.0;
	c.z = 0.0;
#endif
	return c;
}

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
	double r = a/(double)N;
#if TRIDIM == 1
	r *= 1.0/(pow(log(N),2)*500.0);
#endif
	c->x += randomInRange(-r,r);
#if TRIDIM == 1
	c->y += randomInRange(-r,r);
	c->z += randomInRange(-r,r);
#endif
}
