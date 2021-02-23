#include "misc.h"

double randomInRange(double min, double max){
	if(min > max) return 0.0;
	double m = max-min;
	double r = (double)rand()/(double)RAND_MAX;
	return (m*r)+min;
}
