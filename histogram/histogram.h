#include "../state/state.h"



typedef struct histogram {
	unsigned int* histo;
	unsigned int histogram_resolution;
	unsigned int histogram_range;
	unsigned int steps;
} histogram;

void initHistogram(histogram* h, unsigned int histogram_resolution, unsigned int histogram_range);
void addStep(histogram* h, state* s);
void printHistogram(histogram* h);
