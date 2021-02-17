#include "misc.h"

double randomInRange(double min, double max){
	if(min > max) return 0.0;
	double m = max-min;
	double r = (rand()%1729)/1729.0;
	return (m*r)+min;
}
