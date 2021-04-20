#ifndef _histogram_h
#define _histogram_h


#include "../state/state.h"
#include <stdio.h>



typedef struct histogram {
	unsigned int size;
	double delta_x;
	double range; //[-range, range]
	unsigned int iterations;
	void (*addIteration)(struct histogram* h, state *s);
	unsigned int* histo;
} histogram;

histogram* histogramInit(double range, unsigned int size);
histogram* densityProfileInit(double range, unsigned int size);
histogram* distributionInit(double range, unsigned int size);
histogram* densityProfile2DInit(double range, unsigned int size);

void printDensityProfile(histogram* h, FILE *fp);
void printDistribution(histogram* h, FILE *fp);
void printDensityProfile2D(histogram*h, FILE *fp);
void printDensityProfile2DDiag1(histogram*h, FILE *fp);
void printDensityProfile2DDiag2(histogram*h, FILE *fp);



#endif
