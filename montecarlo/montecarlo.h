#include "../state/state.h"
#include "../histogram/histogram.h"
typedef struct montecarlo{
	state* state;
} montecarlo;


montecarlo* montecarloInit(double initial_dispersion);

void runOneStep(montecarlo* mc);

void runNSteps(montecarlo* mc, unsigned int steps);

void printHisto(montecarlo* mc);
