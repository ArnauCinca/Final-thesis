#include "../state/state.h"
#include <stdio.h>



typedef struct histogram {
	unsigned int size;
	double delta_x;
	double range; //[-range, range]
	unsigned int iterations;
	unsigned int* histo;
} histogram;

void initHistogram(histogram* h, double range, unsigned int size);
void addDensityProfile(histogram* h, state* s);
void printHistogram(histogram* h, FILE *fp);
