#ifndef _histogram_h
#define _histogram_h


#include "../state/state.h"
#include <stdio.h>



typedef struct histogram {
	unsigned int size;
	double delta_x;
	double range; //[-range, range]
	unsigned int iterations;
	void (*addIteration)(struct histogram* h, state *s, double center);
	unsigned int* histo;
} histogram;

histogram* histogramInit(double range, unsigned int size);
histogram* densityProfileXInit(double range, unsigned int size);
#if TRIDIM == 1
histogram* densityProfileYInit(double range, unsigned int size);
histogram* densityProfileZInit(double range, unsigned int size);
#endif
histogram* distributionInit(double range, unsigned int size);
histogram* densityProfile2DInit(double range, unsigned int size);

void printDensityProfile(histogram* h, FILE *fp);
void printDistribution(histogram* h, FILE *fp);
void printDensityProfile2D(histogram*h, FILE *fp);
void printDensityProfile2DDiag1(histogram*h, FILE *fp);
void printDensityProfile2DDiag2(histogram*h, FILE *fp);



#endif
