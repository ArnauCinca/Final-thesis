#ifndef _measurements_h
#define _measurements_h


#include "../state/state.h"
#include <stdio.h>



typedef struct measurements {
	unsigned int size;
	double delta_x;
	double range; //[-range, range]
	unsigned int iterations;
	unsigned int* histoX;
#if TRIDIM == 1
	unsigned int* histoY;
	unsigned int* histoZ;
#else
	unsigned int** heatmap;
#endif
} measurements;

// initializes and calculates all the fields in the struct.
void addIteration(measurements* m, state *s);

// add to the graphics the state s, and increments by one the iterations field.
measurements* measurementsInit(double range, unsigned int size);

// print at the file fp the desity profile of the x axis.
void printDensityProfileX(measurements* h, FILE *fp);
#if TRIDIM == 1

// print at the file fp the desity profile of the y axis.
void printDensityProfileY(measurements* h, FILE *fp);

// print at the file fp the desity profile of the z axis.
void printDensityProfileZ(measurements* h, FILE *fp);

#else

// print at the file fp the heat-map of the pair distribution function en the x axis.
void printDensityProfile2D(measurements* h, FILE *fp);

// print at the file fp the [i,-i] diagonal of the heat-map.
void printDensityProfile2DDiag1(measurements* h, FILE *fp);

// print at the file fp the [i,i] diagonal of the heat-map.
void printDensityProfile2DDiag2(measurements* h, FILE *fp);
#endif


#endif
