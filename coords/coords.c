#include "coords.h"
#include <math.h>




double dist(coords i, coords j){
	double dx = i.x-j.x;
	return sqrt(dx*dx);
}




coords coordsRandomInit(){
	coords i;
	i.x = randomInRange(0,1);
	return i;
}

void randomMove(coords* c){
	c->x += randomInRange(-1,1);
}
