#include "../state/state.h"
typedef struct montecarlo{
	unsigned int* histo;
	unsigned int histogram_definition;
	unsigned int histogram_range;
	unsigned int steps;
	state* state;
} montecarlo;


montecarlo* montecarloInit(double initial_dispersion, unsigned int histogram_definition, unsigned int histogram_range);

void runOneStep(montecarlo* mc);

void runNSteps(montecarlo* mc, unsigned int steps);

double centerOfMasesState(montecarlo* mc);

void printHisto(montecarlo* mc);
