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

double E;
double p;
double* s1;

void addIteration(measurements* m, state *s);

measurements* measurementsInit(double range, unsigned int size);

void printDensityProfileX(measurements* h, FILE *fp);
//void printDistribution(measurements* h, FILE *fp);
#if TRIDIM == 1
void printDensityProfileY(measurements* h, FILE *fp);
void printDensityProfileZ(measurements* h, FILE *fp);

#else
void printDensityProfile2D(measurements* h, FILE *fp);
void printDensityProfile2DDiag1(measurements* h, FILE *fp);
void printDensityProfile2DDiag2(measurements* h, FILE *fp);
#endif


#endif
